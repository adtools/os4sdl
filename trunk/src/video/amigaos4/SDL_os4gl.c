/*
    SDL - Simple DirectMedia Layer
    Copyright (C) 1997-2006 Sam Lantinga

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    Sam Lantinga
    slouken@libsdl.org
*/
#include "SDL_config.h"

/*
 * GL support for AmigaOS 4.0 using MiniGL
 *
 * (c) 2005      Thomas Frieden
 * (c) 2005-2006 Richard Drummond
 */

#if SDL_VIDEO_OPENGL

#include "SDL_os4video.h"
#include "SDL_os4utils.h"
#include "SDL_os4blit.h"

#include <proto/exec.h>
#include <proto/Picasso96API.h>

#include <GL/gl.h>
#include <mgl/gl.h>

#define DEBUG
#include "../../main/amigaos4/SDL_os4debug.h"


static struct MiniGLIFace *IMiniGL = 0;
static struct Library *MiniGLBase = 0;
static struct GLContextIFace *IGL;

/* The client program needs access to this context pointer
 * to be able to make GL calls. This presents no problems when
 * it is statically linked against libSDL, but when linked
 * against a shared library version this will require some
 * trickery.
 */
struct GLContextIFace *mini_CurrentContext = 0;

/*
 * Open MiniGL and initialize GL context
 */
int os4video_GL_Init(_THIS, void *bm)
{
	struct SDL_PrivateVideoData *hidden = _this->hidden;

	dprintf("Initializing OpenGL\n");
	MiniGLBase = IExec->OpenLibrary("minigl.library", 0);
	if (!MiniGLBase)
	{
		SDL_SetError("Failed to open minigl.library");
		hidden->OpenGL = FALSE;
		return -1;
	}

	IMiniGL = (struct MiniGLIFace *)IExec->GetInterface(MiniGLBase, "main", 1, NULL);
	if (!IMiniGL)
	{
		SDL_SetError("Failed to obtain minigl.library interface");
		hidden->OpenGL = FALSE;
		IExec->CloseLibrary(MiniGLBase);

		return -1;
	}

	dprintf("Creating context from bitmap %p\n", bm);
	IGL = IMiniGL->CreateContextTags(
							MGLCC_Bitmap,                   bm,
							MGLCC_StencilBuffer,    ((_this->gl_config.stencil_size > 0) ? TRUE : FALSE),
						TAG_DONE);

	if (IGL)
	{
		struct GLContextIFace **target;

		mglMakeCurrent(IGL);
		mglLockMode(MGL_LOCK_SMART);
		hidden->OpenGL = TRUE;

		return 0;
	}
	else
		SDL_SetError("Failed to create MiniGL context");

	return -1;
}

void os4video_GL_Term(_THIS)
{
	struct SDL_PrivateVideoData *hidden = _this->hidden;

	if (hidden->OpenGL)
	{
		IGL->DeleteContext();
		IExec->DropInterface((struct Interface *)IMiniGL);
		IExec->CloseLibrary(MiniGLBase);

		hidden->OpenGL = FALSE;
	}
}

int	os4video_GL_GetAttribute(_THIS, SDL_GLattr attrib, int* value)
{
	struct SDL_PrivateVideoData *hidden = _this->hidden;
	struct BitMap *bm = hidden->screenHWData.bm;
	SDL_PixelFormat pf;
	uint32 rgbFormat;

	if (!bm)
		return -1;

	rgbFormat = IP96->p96GetBitMapAttr(bm, P96BMA_RGBFORMAT);

	if (!os4video_PPFtoPF(&pf, rgbFormat))
		return -1;

	switch (attrib)
	{
		case SDL_GL_RED_SIZE:
			*value = 8-pf.Rloss;
			return 0;

		case SDL_GL_GREEN_SIZE:
			*value = 8-pf.Gloss;
			return 0;

		case SDL_GL_BLUE_SIZE:
			*value = 8-pf.Bloss;
			return 0;

		case SDL_GL_ALPHA_SIZE:
			if (rgbFormat == RGBFB_A8R8G8B8 || rgbFormat == RGBFB_A8B8G8R8
			 || rgbFormat ==  RGBFB_R8G8B8A8 || rgbFormat == RGBFB_B8G8R8A8)
				*value = 8;
			else
				*value = 0;
			return 0;

		case SDL_GL_DOUBLEBUFFER:
//			*value = 1;			/* FIXME */
			*value = _this->gl_config.double_buffer;
			return 0;

		case SDL_GL_BUFFER_SIZE:
			*value = pf.BitsPerPixel;
			return 0;

		case SDL_GL_DEPTH_SIZE:
			glGetIntegerv(GL_DEPTH_BITS, value);
			return 0;

		case SDL_GL_STENCIL_SIZE:
			glGetIntegerv(GL_STENCIL_BITS, value);
			return 0;

		case SDL_GL_STEREO:
		case SDL_GL_MULTISAMPLEBUFFERS:
		case SDL_GL_MULTISAMPLESAMPLES:
		case SDL_GL_ACCUM_RED_SIZE:
		case SDL_GL_ACCUM_GREEN_SIZE:
		case SDL_GL_ACCUM_BLUE_SIZE:
		case SDL_GL_ACCUM_ALPHA_SIZE:
			*value = 0;
			return -1;
	}

	return -1;
}

int	os4video_GL_MakeCurrent(_THIS)
{
	return 0;
}

void os4video_GL_SwapBuffers(_THIS)
{
	struct SDL_PrivateVideoData *hidden = _this->hidden;
	SDL_Surface *video = SDL_VideoSurface;

	if (video && video->flags & SDL_FULLSCREEN)
	{
		mglUnlockDisplay();
		_this->FlipHWSurface(_this, video);
		mglSetBitmap(hidden->screenHWData.bm);
	}
}
/*
void glPopClientAttrib(void)
{
}

void glPushClientAttrib(void)
{
}
*/
#endif
