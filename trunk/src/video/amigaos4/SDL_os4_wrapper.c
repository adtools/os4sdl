/*
    SDL - Simple DirectMedia Layer
    Copyright (C) 1997, 1998, 1999, 2000, 2001  Sam Lantinga

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Sam Lantinga
    slouken@libsdl.org

   AmigaOS4/MiniGL version by andrea@amigasoft.net

   20100316 first version with minigl.library 2.2 functions (unsupported functions
   			are wrapped into an #ifndef __amigaos4__

*/
#include "SDL_config.h"

/* wrapper functions for MiniGL */

#if SDL_VIDEO_OPENGL

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <string.h>

/* The GL API */

/*
 * Miscellaneous
 */

static void AmiglClearIndex( GLfloat c ) {
#ifndef __amigaos4__
    glClearIndex(c);
#endif
 }

static void AmiglClearColor( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha ) {
    glClearColor(red, green, blue, alpha);
 }

static void AmiglClear( GLbitfield mask ) {
    glClear(mask);
 }

static void AmiglIndexMask( GLuint mask ) {
#ifndef __amigaos4__
    glIndexMask(mask);
#endif
 }

void AmiglColorMask( GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha ) {
    glColorMask(red, green, blue, alpha);
}

 void AmiglAlphaFunc( GLenum func, GLclampf ref ) {
    glAlphaFunc(func, ref);
 }

 void AmiglBlendFunc( GLenum sfactor, GLenum dfactor ) {
    glBlendFunc(sfactor, dfactor);
 }

static void AmiglLogicOp( GLenum opcode ) {
    glLogicOp(opcode);
}

 void AmiglCullFace( GLenum mode ) {
    glCullFace(mode);
 }

 void AmiglFrontFace( GLenum mode ) {
    glFrontFace(mode);
 }

 void AmiglPointSize( GLfloat size ) {
    glPointSize(size);
 }

 void AmiglLineWidth( GLfloat width ) {
    glLineWidth(width);
 }

void AmiglLineStipple( GLint factor, GLushort pattern ) {
   glLineStipple(factor, pattern);
}

 void AmiglPolygonMode( GLenum face, GLenum mode ) {
    glPolygonMode(face, mode);
 }

 void AmiglPolygonOffset( GLfloat factor, GLfloat units ) {
    glPolygonOffset(factor, units);
 }

static void AmiglPolygonStipple( const GLubyte *mask ) {
    glPolygonStipple(mask);
 }

static void AmiglGetPolygonStipple( GLubyte *mask ) {
#ifndef __amigaos4__
    glGetPolygonStipple(mask);
#endif
 }

static void AmiglEdgeFlag( GLboolean flag ) {
    glEdgeFlag(flag);
 }

static void AmiglEdgeFlagv( const GLboolean *flag ) {
#ifndef __amigaos4__
    glEdgeFlagv(flag);
#endif
 }

 void AmiglScissor( GLint x, GLint y, GLsizei width, GLsizei height) {
    glScissor(x, y, width, height);
 }

void AmiglClipPlane( GLenum plane, const GLdouble *equation ) {
    glClipPlane(plane, (GLdouble *)equation);
}

static void AmiglGetClipPlane( GLenum plane, GLdouble *equation ) {
    glGetClipPlane(plane, equation);
 }

 void AmiglDrawBuffer( GLenum mode ) {
    glDrawBuffer(mode);
 }

 void AmiglReadBuffer( GLenum mode ) {
    glReadBuffer(mode);
 }

 void AmiglEnable( GLenum cap ) {
    glEnable(cap);
 }

 void AmiglDisable( GLenum cap ) {
    glDisable(cap);
 }

 GLboolean AmiglIsEnabled( GLenum cap ) {
    return glIsEnabled(cap);
 }

 void AmiglEnableClientState( GLenum cap ) {  /* 1.1 */
    glEnableClientState(cap);
 }

 void AmiglDisableClientState( GLenum cap ) {  /* 1.1 */
    glDisableClientState(cap);
 }

static void AmiglGetBooleanv( GLenum pname, GLboolean *params ) {
    glGetBooleanv(pname, params);
 }

 void AmiglGetDoublev( GLenum pname, GLdouble *params ) {
    glGetDoublev(pname, params);
 }

 void AmiglGetFloatv( GLenum pname, GLfloat *params ) {
    glGetFloatv(pname, params);
 }

 void AmiglGetIntegerv( GLenum pname, GLint *params ) {
    glGetIntegerv(pname, params);
 }

 void AmiglPushAttrib( GLbitfield mask ) {
    glPushAttrib(mask);
 }

 void AmiglPopAttrib( void ) {
    glPopAttrib();
 }

 void AmiglPushClientAttrib( GLbitfield mask ) {  /* 1.1 */
    glPushClientAttrib(mask);
 }

 void AmiglPopClientAttrib( void ) {  /* 1.1 */
    glPopClientAttrib();
 }

static GLint AmiglRenderMode( GLenum mode ) {
   return glRenderMode(mode);
}

static GLenum AmiglGetError( void ) {
    return glGetError();
}

static const GLubyte* AmiglGetString( GLenum name ) {
    return glGetString(name);
 }

static void AmiglFinish( void ) {
    glFinish();
 }

static void AmiglFlush( void ) {
    glFlush();
 }

static void AmiglHint( GLenum target, GLenum mode ) {
    glHint(target, mode);
 }

/*
 * Depth Buffer
 */

 void AmiglClearDepth( GLclampd depth ) {
    glClearDepth(depth);
 }

 void AmiglDepthFunc( GLenum func ) {
    glDepthFunc(func);
 }

 void AmiglDepthMask( GLboolean flag ) {
    glDepthMask(flag);
 }

 void AmiglDepthRange( GLclampd near_val, GLclampd far_val ) {
    glDepthRange(near_val, far_val);
 }

/*
 * Accumulation Buffer
 */

static void AmiglClearAccum( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha ) {
#ifndef __amigaos4__
    glClearAccum(red, green, blue, alpha);
#endif
 }

static void AmiglAccum( GLenum op, GLfloat value ) {
#ifndef __amigaos4__
    glAccum(op, value);
#endif
 }

/*
 * Transformation
 */

 void AmiglMatrixMode( GLenum mode ) {
    glMatrixMode(mode);
 }

 void AmiglOrtho( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val ) {
    glOrtho(left, right, bottom, top, near_val, far_val);
 }

 void AmiglFrustum( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val ) {
    glFrustum(left, right, bottom, top, near_val, far_val);
 }

 void AmiglViewport( GLint x, GLint y, GLsizei width, GLsizei height ) {
    glViewport(x, y, width, height);
 }

 void AmiglPushMatrix( void ) {
    glPushMatrix();
 }

 void AmiglPopMatrix( void ) {
    glPopMatrix();
 }

 void AmiglLoadIdentity( void ) {
    glLoadIdentity();
 }

 void AmiglLoadMatrixd( const GLdouble *m ) {
    glLoadMatrixd(m);
 }

 void AmiglLoadMatrixf( const GLfloat *m ) {
    glLoadMatrixf(m);
 }

 void AmiglMultMatrixd( const GLdouble *m ) {
    glMultMatrixd(m);
 }

 void AmiglMultMatrixf( const GLfloat *m ) {
    glMultMatrixf(m);
 }

static void AmiglRotated( GLdouble angle, GLdouble x, GLdouble y, GLdouble z ) {
    glRotated(angle, x, y, z);
 }

 void AmiglRotatef( GLfloat angle, GLfloat x, GLfloat y, GLfloat z ) {
    glRotatef(angle, x, y, z);
 }

 void AmiglScaled( GLdouble x, GLdouble y, GLdouble z ) {
    glScaled(x, y, z);
 }

 void AmiglScalef( GLfloat x, GLfloat y, GLfloat z ) {
    glScalef(x, y, z);
 }

static void AmiglTranslated( GLdouble x, GLdouble y, GLdouble z ) {
    glTranslated(x, y, z);
 }

static void AmiglTranslatef( GLfloat x, GLfloat y, GLfloat z ) {
    glTranslatef(x, y, z);
 }

/*
 * Display Lists
 */

 GLboolean AmiglIsList( GLuint list ) {
    return glIsList(list);
 }

 void AmiglDeleteLists( GLuint list, GLsizei range ) {
    glDeleteLists(list, range);
 }

 GLuint AmiglGenLists( GLsizei range ) {
    return glGenLists(range);
 }

 void AmiglNewList( GLuint list, GLenum mode ) {
    glNewList(list, mode);
 }

 void AmiglEndList( void ) {
    glEndList();
 }

 void AmiglCallList( GLuint list ) {
    glCallList(list);
 }

 void AmiglCallLists( GLsizei n, GLenum type, GLvoid *lists ) {
    glCallLists(n, type, lists);
 }

 void AmiglListBase( GLuint base ) {
    glListBase(base);
 }

/*
 * Drawing Functions
 */

 void AmiglBegin( GLenum mode ) {
    glBegin(mode);
 }

 void AmiglEnd( void ) {
    glEnd();
 }

static void AmiglVertex2d( GLdouble x, GLdouble y )   { glVertex2d(x, y); }
static void AmiglVertex2f( GLfloat x, GLfloat y )         { glVertex2f(x, y); }
static void AmiglVertex2i( GLint x, GLint y )             { glVertex2i(x, y); }
static void AmiglVertex2s( GLshort x, GLshort y )
 {
   glVertex2s(x, y);
 }

 void AmiglVertex3d( GLdouble x, GLdouble y, GLdouble z )   { glVertex3d(x, y, z); }
 void AmiglVertex3f( GLfloat x, GLfloat y, GLfloat z )      { glVertex3f(x, y, z); }
 void AmiglVertex3i( GLint x, GLint y, GLint z )
 {
   glVertex3i(x, y, z);
 }

static void AmiglVertex3s( GLshort x, GLshort y, GLshort z )
 {
   glVertex3s(x, y, z);
 }

static void AmiglVertex4d( GLdouble x, GLdouble y, GLdouble z, GLdouble w )
 {
   glVertex4d(x, y, z, w);
 }

 void AmiglVertex4f( GLfloat x, GLfloat y, GLfloat z, GLfloat w )       { glVertex4f(x, y, z, w); }
 void AmiglVertex4i( GLint x, GLint y, GLint z, GLint w )
 {
   glVertex4i(x, y, z, w);
 }

 void AmiglVertex4s( GLshort x, GLshort y, GLshort z, GLshort w )
 {
   glVertex4s(x, y, z, w);
 }

static void AmiglVertex2dv( const GLdouble *v )
 {
   glVertex2dv(v);
 }

static void AmiglVertex2fv( const GLfloat *v )    { glVertex2fv(v); }

static void AmiglVertex2iv( const GLint *v )
 {
   glVertex2iv(v);
}

static void AmiglVertex2sv( const GLshort *v )    { glVertex2sv(v); }

 void AmiglVertex3dv( GLdouble *v )
 {
   glVertex3dv(v);
 }

 void AmiglVertex3fv( GLfloat *v )    { glVertex3fv(v); }

 void AmiglVertex3iv( const GLint *v )
 {
   glVertex3iv(v);
 }

static void AmiglVertex3sv( const GLshort *v )
{
   glVertex3sv(v);
}

 void AmiglVertex4dv( GLdouble *v )
 {
   glVertex4dv(v);
 }

 void AmiglVertex4fv( GLfloat *v )    { glVertex4fv(v); }
static void AmiglVertex4iv( const GLint *v )
 {
   glVertex4iv(v);
 }

static void AmiglVertex4sv( const GLshort *v )
 {
   glVertex4sv(v);
 }

static void AmiglNormal3b( GLbyte nx, GLbyte ny, GLbyte nz )
{
   glNormal3b(nx, ny, nz);
}

void AmiglNormal3d( GLdouble nx, GLdouble ny, GLdouble nz )
{
   glNormal3d(nx, ny, nz);
}

 void AmiglNormal3f( GLfloat nx, GLfloat ny, GLfloat nz )   { glNormal3f(nx, ny, nz); }

static void AmiglNormal3i( GLint nx, GLint ny, GLint nz )
{
   glNormal3i(nx, ny, nz);
}

void AmiglNormal3s( GLshort nx, GLshort ny, GLshort nz )
{
   glNormal3s(nx, ny, nz);
}

static void AmiglNormal3bv( const GLbyte *v )
 {
   glNormal3bv(v);
 }

void AmiglNormal3dv( const GLdouble *v )
{
   glNormal3dv(v);
}

 void AmiglNormal3fv( GLfloat *v )    { glNormal3fv(v); }

static void AmiglNormal3iv( const GLint *v )
 {
   glNormal3iv(v);
 }

 void AmiglNormal3sv( const GLshort *v )
 {
   glNormal3sv(v);
 }

static void AmiglIndexd( GLdouble c )
 {
#ifndef __amigaos4__
   glIndexd(c);
#endif
 }

static void AmiglIndexf( GLfloat c )
 {
#ifndef __amigaos4__
   glIndexf(c);
#endif
 }

 void AmiglIndexi( GLint c )
 {
#ifndef __amigaos4__
   glIndexi(c);
#endif
 }

static void AmiglIndexs( GLshort c )
 {
#ifndef __amigaos4__
   glIndexs(c);
#endif
 }

static void AmiglIndexub( GLubyte c )
 {
#ifndef __amigaos4__
   glIndexub(c);
#endif
 }

static void AmiglIndexdv( const GLdouble *c )
 {
#ifndef __amigaos4__
   glIndexdv(c);
#endif
 }

static void AmiglIndexfv( const GLfloat *c )
 {
#ifndef __amigaos4__
   glIndexfv(c);
#endif
 }

static void AmiglIndexiv( const GLint *c )
 {
#ifndef __amigaos4__
   glIndexiv(c);
#endif
 }

static void AmiglIndexsv( const GLshort *c )
 {
#ifndef __amigaos4__
   glIndexsv(c);
#endif
 }

static void AmiglIndexubv( const GLubyte *c )
 {
#ifndef __amigaos4__
   glIndexubv(c);
#endif
 }

static void AmiglColor3b( GLbyte red, GLbyte green, GLbyte blue )
 {
   glColor3b(red, green, blue);
 }

void AmiglColor3d( GLdouble red, GLdouble green, GLdouble blue )
{
   glColor3d(red, green, blue);
}

 void AmiglColor3f( GLfloat red, GLfloat green, GLfloat blue )      { glColor3f(red, green, blue); }

static void AmiglColor3i( GLint red, GLint green, GLint blue )
 {
   glColor3i(red, green, blue);
 }

static void AmiglColor3s( GLshort red, GLshort green, GLshort blue )
 {
   glColor3s(red, green, blue);
 }

 void AmiglColor3ub( GLubyte red, GLubyte green, GLubyte blue ) { glColor3ub(red, green, blue); }
static void AmiglColor3ui( GLuint red, GLuint green, GLuint blue )
 {
   glColor3ui(red, green, blue);
 }

static void AmiglColor3us( GLushort red, GLushort green, GLushort blue )
 {
   glColor3us(red, green, blue);
 }

 void AmiglColor4b( GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha )
 {
   glColor4b(red, green, blue, alpha);
 }

 void AmiglColor4d( GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha )
 {
   glColor4d(red, green, blue, alpha);
 }

 void AmiglColor4f( GLfloat red, GLfloat green,GLfloat blue, GLfloat alpha )    { glColor4f(red, green, blue, alpha); }

static void AmiglColor4i( GLint red, GLint green, GLint blue, GLint alpha )
 {
   glColor4i(red, green, blue, alpha);
 }

static void AmiglColor4s( GLshort red, GLshort green, GLshort blue, GLshort alpha )
 {
   glColor4s(red, green, blue, alpha);
 }

 void AmiglColor4ub( GLubyte red, GLubyte green,
                    GLubyte blue, GLubyte alpha )   { glColor4ub(red, green, blue, alpha); }

static void AmiglColor4ui( GLuint red, GLuint green, GLuint blue, GLuint alpha )
 {
   glColor4ui(red, green, blue, alpha);
 }

static void AmiglColor4us( GLushort red, GLushort green, GLushort blue, GLushort alpha )
 {
   glColor4us(red, green, blue, alpha);
 }

static void AmiglColor3bv( const GLbyte *v )
 {
   glColor3bv(v);
 }

 void AmiglColor3dv( const GLdouble *v )
 {
   glColor3dv(v);
 }

 void AmiglColor3fv( GLfloat *v ) { glColor3fv(v); }

static void AmiglColor3iv( const GLint *v )
 {
   glColor3iv(v);
 }

static void AmiglColor3sv( const GLshort *v )
 {
   glColor3sv(v);
 }

 void AmiglColor3ubv( GLubyte *v )    { glColor3ubv(v); }

static void AmiglColor3uiv( const GLuint *v )
 {
   glColor3uiv(v);
 }

static void AmiglColor3usv( const GLushort *v )
 {
   glColor3usv(v);
 }

static void AmiglColor4bv( const GLbyte *v )
 {
   glColor4bv(v);
 }

 void AmiglColor4dv( const GLdouble *v )
 {
   glColor4dv(v);
 }

 void AmiglColor4fv( GLfloat *v ) { glColor4fv(v); }

static void AmiglColor4iv( const GLint *v )
 {
   glColor4iv(v);
 }

static void AmiglColor4sv( const GLshort *v )
 {
   glColor4sv(v);
 }

 void AmiglColor4ubv( GLubyte *v )    { glColor4ubv(v); }

static void AmiglColor4uiv( const GLuint *v )
 {
   glColor4uiv(v);
 }

static void AmiglColor4usv( const GLushort *v )
 {
   glColor4usv(v);
 }

 void AmiglTexCoord1d( GLdouble s )
 {
   glTexCoord1d(s);
 }

 void AmiglTexCoord1f( GLfloat s )
 {
   glTexCoord1f(s);
 }

static void AmiglTexCoord1i( GLint s )
 {
   glTexCoord1i(s);
 }

static void AmiglTexCoord1s( GLshort s )
 {
#ifndef __amigaos4__
   glTexCoord1s(s);
#endif
 }

 void AmiglTexCoord2d( GLdouble s, GLdouble t )
 {
   glTexCoord2d(s, t);
 }

 void AmiglTexCoord2f( GLfloat s, GLfloat t )   { glTexCoord2f(s, t); }

 void AmiglTexCoord2i( GLint s, GLint t )           { glTexCoord2i(s, t); }

static void AmiglTexCoord2s( GLshort s, GLshort t )
 {
#ifndef __amigaos4__
   glTexCoord2s(s, t);
#endif
 }

static void AmiglTexCoord3d( GLdouble s, GLdouble t, GLdouble r )
 {
#ifndef __amigaos4__
   glTexCoord3d(s, t, r);
#endif
 }

 void AmiglTexCoord3f( GLfloat s, GLfloat t, GLfloat r )
 {
   glTexCoord3f(s, t, r);
 }

static void AmiglTexCoord3i( GLint s, GLint t, GLint r )
 {
#ifndef __amigaos4__
   glTexCoord3i(s, t, r);
#endif
 }

static void AmiglTexCoord3s( GLshort s, GLshort t, GLshort r )
 {
#ifndef __amigaos4__
   glTexCoord3s(s, t, r);
#endif
 }

static void AmiglTexCoord4d( GLdouble s, GLdouble t, GLdouble r, GLdouble q )
 {
 #ifndef __amigaos4__
   glTexCoord4d(s, t, r, q);
 #endif
 }

static void AmiglTexCoord4f( GLfloat s, GLfloat t, GLfloat r, GLfloat q )
 {
   glTexCoord4f(s, t, r, q);
 }

static void AmiglTexCoord4i( GLint s, GLint t, GLint r, GLint q )
 {
 #ifndef __amigaos4__
   glTexCoord4i(s, t, r, q);
 #endif
 }

static void AmiglTexCoord4s( GLshort s, GLshort t, GLshort r, GLshort q )
 {
 #ifndef __amigaos4__
   glTexCoord4s(s, t, r, q);
 #endif
 }

static void AmiglTexCoord1dv( const GLdouble *v )
 {
#ifndef __amigaos4__
   glTexCoord1dv(v);
#endif
 }

static void AmiglTexCoord1fv( const GLfloat *v )
 {
#ifndef __amigaos4__
   glTexCoord1fv(v);
#endif
 }

static void AmiglTexCoord1iv( const GLint *v )
 {
#ifndef __amigaos4__
   glTexCoord1iv(v);
#endif
 }

static void AmiglTexCoord1sv( const GLshort *v )
 {
#ifndef __amigaos4__
   glTexCoord1sv(v);
#endif
 }

static void AmiglTexCoord2dv( const GLdouble *v )
 {
#ifndef __amigaos4__
   glTexCoord2dv(v);
#endif
 }

static void AmiglTexCoord2fv( GLfloat *v )  { glTexCoord2fv(v); }

static void AmiglTexCoord2iv( const GLint *v )
 {
   glTexCoord2iv(v);
 }

static void AmiglTexCoord2sv( const GLshort *v )
 {
#ifndef __amigaos4__
   glTexCoord2sv(v);
#endif
 }

static void AmiglTexCoord3dv( const GLdouble *v )
 {
#ifndef __amigaos4__
   glTexCoord3dv(v);
#endif
 }

static void AmiglTexCoord3fv( const GLfloat *v )
 {
   glTexCoord3fv(v);
 }

static void AmiglTexCoord3iv( const GLint *v )
 {
#ifndef __amigaos4__
   glTexCoord3iv(v);
#endif
 }

static void AmiglTexCoord3sv( const GLshort *v )
 {
#ifndef __amigaos4__
   glTexCoord3sv(v);
#endif
 }

static void AmiglTexCoord4dv( const GLdouble *v )
 {
#ifndef __amigaos4__
   glTexCoord4dv(v);
#endif
 }

static void AmiglTexCoord4fv( const GLfloat *v )
 {
   glTexCoord4fv(v);
 }

static void AmiglTexCoord4iv( const GLint *v )
 {
#ifndef __amigaos4__
   glTexCoord4iv(v);
#endif
 }

static void AmiglTexCoord4sv( const GLshort *v )
 {
#ifndef __amigaos4__
   glTexCoord4sv(v);
#endif
 }

static void AmiglRasterPos2d( GLdouble x, GLdouble y )
 {
   glRasterPos2d(x, y);
 }

static void AmiglRasterPos2f( GLfloat x, GLfloat y )      { glRasterPos2f(x, y); }

static void AmiglRasterPos2i( GLint x, GLint y )          { glRasterPos2i(x, y); }

static void AmiglRasterPos2s( GLshort x, GLshort y )
 {
   glRasterPos2s(x, y);
 }

static void AmiglRasterPos3d( GLdouble x, GLdouble y, GLdouble z )    { glRasterPos3d(x, y, z); }

static void AmiglRasterPos3f( GLfloat x, GLfloat y, GLfloat z )       { glRasterPos3f(x, y, z); }

void AmiglRasterPos3i( GLint x, GLint y, GLint z )
{
   glRasterPos3i(x, y, z);
}

void AmiglRasterPos3s( GLshort x, GLshort y, GLshort z )
{
   glRasterPos3s(x, y, z);
}

static void AmiglRasterPos4d( GLdouble x, GLdouble y, GLdouble z, GLdouble w )
 {
   glRasterPos4d(x, y, z, w);
 }

static void AmiglRasterPos4f( GLfloat x, GLfloat y, GLfloat z, GLfloat w )
 {
   glRasterPos4f(x, y, z, w);
 }

static void AmiglRasterPos4i( GLint x, GLint y, GLint z, GLint w )
 {
   glRasterPos4i(x, y, z, w);
 }

static void AmiglRasterPos4s( GLshort x, GLshort y, GLshort z, GLshort w )
 {
   glRasterPos4s(x, y, z, w);
 }

static void AmiglRasterPos2dv( const GLdouble *v )
 {
   glRasterPos2dv(v);
 }

void AmiglRasterPos2fv( const GLfloat *v )
{
   glRasterPos2fv((GLfloat *)v);
}

static void AmiglRasterPos2iv( const GLint *v )
 {
   glRasterPos2iv(v);
 }

static void AmiglRasterPos2sv( const GLshort *v )
 {
   glRasterPos2sv(v);
 }

static void AmiglRasterPos3dv( const GLdouble *v )
 {
   glRasterPos3dv(v);
 }

void AmiglRasterPos3fv( const GLfloat *v )
{
   glRasterPos3fv((GLfloat *)v);
}

static void AmiglRasterPos3iv( const GLint *v )
 {
   glRasterPos3iv(v);
 }

static void AmiglRasterPos3sv( const GLshort *v )
 {
   glRasterPos3sv(v);
 }

static void AmiglRasterPos4dv( const GLdouble *v )
 {
   glRasterPos4dv(v);
 }

static void AmiglRasterPos4fv( const GLfloat *v )
 {
   glRasterPos4fv(v);
 }

static void AmiglRasterPos4iv( const GLint *v )
 {
   glRasterPos4iv(v);
 }

static void AmiglRasterPos4sv( const GLshort *v )
 {
   glRasterPos4sv(v);
 }

static void AmiglRectd( GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2 )  { glRectd(x1, y1, x2, y2); }
static void AmiglRectf( GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2 )      { glRectf(x1, y1, x2, y2); }
static void AmiglRecti( GLint x1, GLint y1, GLint x2, GLint y2 )                  { glRecti(x1, y1, x2, y2); }

static void AmiglRects( GLshort x1, GLshort y1, GLshort x2, GLshort y2 )
 {
   glRects(x1, y1, x2, y2);
 }

static void AmiglRectdv( GLdouble *v1, GLdouble *v2 ) { glRectdv(v1, v2); }
static void AmiglRectfv( GLfloat *v1,  GLfloat *v2 )   { glRectfv(v1, v2); }
static void AmiglRectiv( GLint *v1, GLint *v2 )           { glRectiv(v1, v2); }

static void AmiglRectsv( const GLshort *v1, const GLshort *v2 )
 {
   glRectsv(v1, v2);
 }

/*
 * Vertex Arrays  (1.1)
 */

static void AmiglVertexPointer( GLint size, GLenum type, GLsizei stride, const GLvoid *ptr ) {
        glVertexPointer(size, type, stride, ptr);
 }

static void AmiglNormalPointer( GLenum type, GLsizei stride, const GLvoid *ptr )  {
        glNormalPointer(type, stride, ptr);
 }

static void AmiglColorPointer( GLint size, GLenum type, GLsizei stride, const GLvoid *ptr ) {
        glColorPointer(size, type, stride, ptr);
 }

static void AmiglIndexPointer( GLenum type, GLsizei stride, const GLvoid *ptr )   {
#ifndef __amigaos4__
        glIndexPointer(type, stride, ptr);
#endif
 }

static void AmiglTexCoordPointer( GLint size, GLenum type, GLsizei stride, const GLvoid *ptr )    {
        glTexCoordPointer(size, type, stride, ptr);
 }

static void AmiglEdgeFlagPointer( GLsizei stride, const GLboolean *ptr )  {
#ifndef __amigaos4__
        glEdgeFlagPointer(stride, ptr);
#endif
 }

static void AmiglGetPointerv( GLenum pname, void **params )   {
#ifndef __amigaos4__
        glGetPointerv(pname, params);
#endif
 }

static void AmiglArrayElement( GLint i )  { glArrayElement(i); }

static void AmiglDrawArrays( GLenum mode, GLint first, GLsizei count )    {
        glDrawArrays(mode, first, count);
 }

static void AmiglDrawElements( GLenum mode, GLsizei count, GLenum type, GLvoid *indices ) {
        glDrawElements(mode, count, type, indices);
 }

static void AmiglInterleavedArrays( GLenum format, GLsizei stride, const GLvoid *pointer ) {
        glInterleavedArrays(format, stride, pointer);
 }

/*
 * Lighting
 */

static void AmiglShadeModel( GLenum mode )    { glShadeModel(mode); }

static void AmiglLightf( GLenum light, GLenum pname, GLfloat param )  { glLightf(light, pname, param); }
static void AmiglLighti( GLenum light, GLenum pname, GLint param )
 {
   glLighti(light, pname, param);
 }

static void AmiglLightfv( GLenum light, GLenum pname,
                   GLfloat *params )          { glLightfv(light, pname, params); }
static void AmiglLightiv( GLenum light, GLenum pname, const GLint *params )
 {
   glLightiv(light, pname, params);
 }

static void AmiglGetLightfv( GLenum light, GLenum pname, GLfloat *params )
 {
   glGetLightfv(light, pname, params);
 }

static void AmiglGetLightiv( GLenum light, GLenum pname, GLint *params )
 {
   glGetLightiv(light, pname, params);
 }

static void AmiglLightModelf( GLenum pname, GLfloat param )               { glLightModelf(pname, param); }
static void AmiglLightModeli( GLenum pname, GLint param )             { glLightModeli(pname, param); }
static void AmiglLightModelfv( GLenum pname, GLfloat *params )  { glLightModelfv(pname, params); }
static void AmiglLightModeliv( GLenum pname, const GLint *params )
 {
   glLightModeliv(pname, params);
}

void AmiglMaterialf( GLenum face, GLenum pname, GLfloat param )        { glMaterialf(face, pname, param); }
void AmiglMateriali( GLenum face, GLenum pname, GLint param )
{
   glMateriali(face, pname, param);
}

static void AmiglMaterialfv( GLenum face, GLenum pname, GLfloat *params )   { glMaterialfv(face, pname, params); }
static void AmiglMaterialiv( GLenum face, GLenum pname, const GLint *params )
 {
   glMaterialiv(face, pname, params);
 }

static void AmiglGetMaterialfv( GLenum face, GLenum pname, GLfloat *params )
 {
   glGetMaterialfv(face, pname, params);
}

static void AmiglGetMaterialiv( GLenum face, GLenum pname, GLint *params )
 {
   glGetMaterialiv(face, pname, params);
 }

static void AmiglColorMaterial( GLenum face, GLenum mode )    { glColorMaterial(face, mode); }

/*
 * Raster functions
 */

static void AmiglPixelZoom( GLfloat xfactor, GLfloat yfactor )
 {
   glPixelZoom(xfactor, yfactor);
 }

static void AmiglPixelStoref( GLenum pname, GLfloat param )   { glPixelStoref(pname, param); }
static void AmiglPixelStorei( GLenum pname, GLint param ) { glPixelStorei(pname, param); }

static void AmiglPixelTransferf( GLenum pname, GLfloat param )
 {
   glPixelTransferf(pname, param);
 }

static void AmiglPixelTransferi( GLenum pname, GLint param )
 {
   glPixelTransferi(pname, param);
 }

static void AmiglPixelMapfv( GLenum map, GLint mapsize, const GLfloat *values )
 {
#ifndef __amigaos4__
   glPixelMapfv(map, mapsize, values);
#endif
 }

static void AmiglPixelMapuiv( GLenum map, GLint mapsize, const GLuint *values )
 {
#ifndef __amigaos4__
   glPixelMapuiv(map, mapsize, values);
#endif
 }

static void AmiglPixelMapusv( GLenum map, GLint mapsize, const GLushort *values )
 {
#ifndef __amigaos4__
   glPixelMapusv(map, mapsize, values);
#endif
 }

static void AmiglGetPixelMapfv( GLenum map, GLfloat *values )
 {
#ifndef __amigaos4__
   glGetPixelMapfv(map, values);
#endif
 }

static void AmiglGetPixelMapuiv( GLenum map, GLuint *values )
 {
#ifndef __amigaos4__
   glGetPixelMapuiv(map, values);
#endif
 }

static void AmiglGetPixelMapusv( GLenum map, GLushort *values )
 {
#ifndef __amigaos4__
   glGetPixelMapusv(map, values);
#endif
 }

static void AmiglBitmap( GLsizei width, GLsizei height,
                  GLfloat xorig, GLfloat yorig,
                  GLfloat xmove, GLfloat ymove,
                  const GLubyte *bitmap )   {

        glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap);
 }

static void AmiglReadPixels( GLint x, GLint y,
                      GLsizei width, GLsizei height,
                      GLenum format, GLenum type,
                      GLvoid *pixels )  {
        glReadPixels(x, y, width, height, format, type, pixels);
 }

static void AmiglDrawPixels( GLsizei width, GLsizei height,
                      GLenum format, GLenum type,
                      const GLvoid *pixels )    {
        glDrawPixels(width, height, format, type, pixels);
 }

static void AmiglCopyPixels( GLint x, GLint y,
                      GLsizei width, GLsizei height,
                      GLenum type ) {
        glCopyPixels(x, y, width, height, type);
 }

/*
 * Stenciling
 */

static void AmiglStencilFunc( GLenum func, GLint ref, GLuint mask )   {
        glStencilFunc(func, ref, mask);
 }

static void AmiglStencilMask( GLuint mask ) {
        glStencilMask(mask);
 }

static void AmiglStencilOp( GLenum fail, GLenum zfail, GLenum zpass ) {
        glStencilOp(fail, zfail, zpass);
 }

static void AmiglClearStencil( GLint s ) {
        glClearStencil(s);
 }

/*
 * Texture mapping
 */

static void AmiglTexGend( GLenum coord, GLenum pname, GLdouble param )
 {
#ifndef __amigaos4__
   glTexGend(coord, pname, param);
#endif
 }

static void AmiglTexGenf( GLenum coord, GLenum pname, GLfloat param )
{
#ifndef __amigaos4__
	glTexGenf(coord, pname, param);
#endif
}
static void AmiglTexGeni( GLenum coord, GLenum pname, GLint param )       { glTexGeni(coord, pname, param); }

static void AmiglTexGendv( GLenum coord, GLenum pname, const GLdouble *params )
 {
#ifndef __amigaos4__
   glTexGendv(coord, pname, params);
#endif
 }

static void AmiglTexGenfv( GLenum coord, GLenum pname, GLfloat *params )
 {
   glTexGenfv(coord, pname, params);
 }

static void AmiglTexGeniv( GLenum coord, GLenum pname, const GLint *params )
 {
#ifndef __amigaos4__
   glTexGeniv(coord, pname, params);
#endif
 }

static void AmiglGetTexGendv( GLenum coord, GLenum pname, GLdouble *params )
 {
#ifndef __amigaos4__
   glGetTexGendv(coord, pname, params);
#endif
 }

static void AmiglGetTexGenfv( GLenum coord, GLenum pname, GLfloat *params )
 {
#ifndef __amigaos4__
   glGetTexGenfv(coord, pname, params);
#endif
 }

static void AmiglGetTexGeniv( GLenum coord, GLenum pname, GLint *params )
 {
#ifndef __amigaos4__
   glGetTexGeniv(coord, pname, params);
#endif
 }

static void AmiglTexEnvf( GLenum target, GLenum pname, GLfloat param )
 {
   glTexEnvf(target, pname, param);
 }

static void AmiglTexEnvi( GLenum target, GLenum pname, GLint param )
 {
   glTexEnvi(target, pname, param);
 }

static void AmiglTexEnvfv( GLenum target, GLenum pname, const GLfloat *params )
 {
   glTexEnvfv(target, pname, params);
 }

static void AmiglTexEnviv( GLenum target, GLenum pname, const GLint *params )
 {
   glTexEnviv(target, pname, params);
 }

static void AmiglGetTexEnvfv( GLenum target, GLenum pname, GLfloat *params )
 {
#ifndef __amigaos4__
   glGetTexEnvfv(target, pname, params);
#endif
 }

static void AmiglGetTexEnviv( GLenum target, GLenum pname, GLint *params )
 {
   glGetTexEnviv(target, pname, params);
 }

static void AmiglTexParameterf( GLenum target, GLenum pname, GLfloat param )  { glTexParameterf(target, pname, param); }
static void AmiglTexParameteri( GLenum target, GLenum pname, GLint param )        { glTexParameteri(target, pname, param); }

static void AmiglTexParameterfv( GLenum target, GLenum pname, const GLfloat *params ) {
        glTexParameterfv(target, pname, params);
 }
static void AmiglTexParameteriv( GLenum target, GLenum pname, const GLint *params ) {
        glTexParameteriv(target, pname, params);
 }

static void AmiglGetTexParameterfv( GLenum target, GLenum pname, GLfloat *params) {
        glGetTexParameterfv(target, pname, params);
 }

static void AmiglGetTexParameteriv( GLenum target, GLenum pname, GLint *params ) {
        glGetTexParameteriv(target, pname, params);
 }

static void AmiglGetTexLevelParameterfv( GLenum target, GLint level, GLenum pname, GLfloat *params ) {
        glGetTexLevelParameterfv(target, level, pname, params);
 }

static void AmiglGetTexLevelParameteriv( GLenum target, GLint level, GLenum pname, GLint *params ) {
        glGetTexLevelParameteriv(target, level, pname, params);
 }

static void AmiglTexImage1D( GLenum target, GLint level,
                      GLint internalFormat,
                      GLsizei width, GLint border,
                      GLenum format, GLenum type,
                      const GLvoid *pixels )    {
        glTexImage1D(target, level, internalFormat,
                      width, border, format, type, pixels);
 }

static void AmiglTexImage2D( GLenum target, GLint level,
                      GLint internalFormat,
                      GLsizei width, GLsizei height,
                      GLint border, GLenum format, GLenum type,
                      GLvoid *pixels )    {

        glTexImage2D(target, level, internalFormat,
                      width, height, border, format, type, pixels);
 }

static void AmiglGetTexImage( GLenum target, GLint level,
                       GLenum format, GLenum type,
                       GLvoid *pixels ) {
        glGetTexImage(target, level, format, type, pixels);
 }

/* 1.1 functions */

static void AmiglGenTextures( GLsizei n, GLuint *textures )   {
        glGenTextures(n, textures);
 }

static void AmiglDeleteTextures( GLsizei n, const GLuint *textures)   {
        glDeleteTextures(n, textures);
 }

static void AmiglBindTexture( GLenum target, GLuint texture ) {
        glBindTexture(target, texture);
 }

static void AmiglPrioritizeTextures( GLsizei n, const GLuint *textures, const GLclampf *priorities )  {
        glPrioritizeTextures(n, textures, priorities);
 }

 GLboolean AmiglAreTexturesResident( GLsizei n, const GLuint *textures, GLboolean *residences ) {
        return glAreTexturesResident(n, textures, residences);
 }

 GLboolean AmiglIsTexture( GLuint texture ) {
        return glIsTexture(texture);
 }

static void AmiglTexSubImage1D( GLenum target, GLint level,
                     GLint xoffset,
                     GLsizei width, GLenum format,
                     GLenum type, const GLvoid *pixels ) {
        glTexSubImage1D(target, level, xoffset, width, format, type, pixels);
 }

static void AmiglTexSubImage2D( GLenum target, GLint level,
                     GLint xoffset, GLint yoffset,
                     GLsizei width, GLsizei height,
                     GLenum format, GLenum type,
                     GLvoid *pixels ) {

        glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
 }

static void AmiglCopyTexImage1D( GLenum target, GLint level,
                      GLenum internalformat,
                      GLint x, GLint y,
                      GLsizei width, GLint border ) {
        glCopyTexImage1D(target, level, internalformat, x, y, width, border);
 }

static void AmiglCopyTexImage2D( GLenum target, GLint level,
                      GLenum internalformat,
                      GLint x, GLint y,
                      GLsizei width, GLsizei height,
                      GLint border ){
        glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
 }

static void AmiglCopyTexSubImage1D( GLenum target, GLint level,
                         GLint xoffset, GLint x, GLint y,
                         GLsizei width ) {
        glCopyTexSubImage1D(target, level, xoffset, x, y, width);
 }

static void AmiglCopyTexSubImage2D( GLenum target, GLint level,
                         GLint xoffset, GLint yoffset,
                         GLint x, GLint y,
                         GLsizei width, GLsizei height ) {
        glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
 }

/*
 * Evaluators
 */

static void AmiglMap1d( GLenum target, GLdouble u1, GLdouble u2,
                 GLint stride,
                 GLint order, const GLdouble *points ) {
        glMap1d(target, u1, u2, stride, order, points);
 }
static void AmiglMap1f( GLenum target, GLfloat u1, GLfloat u2,
                 GLint stride,
                 GLint order, const GLfloat *points ) {
        glMap1f(target, u1, u2, stride, order, points);
 }

static void AmiglMap2d( GLenum target,
             GLdouble u1, GLdouble u2, GLint ustride, GLint uorder,
             GLdouble v1, GLdouble v2, GLint vstride, GLint vorder,
             const GLdouble *points ) {
        glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
 }
static void AmiglMap2f( GLenum target,
             GLfloat u1, GLfloat u2, GLint ustride, GLint uorder,
             GLfloat v1, GLfloat v2, GLint vstride, GLint vorder,
             const GLfloat *points ) {
        glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
 }

static void AmiglGetMapdv( GLenum target, GLenum query, GLdouble *v ) {
        glGetMapdv(target, query, v);
 }
static void AmiglGetMapfv( GLenum target, GLenum query, GLfloat *v ) {
        glGetMapfv(target, query, v);
 }
static void AmiglGetMapiv( GLenum target, GLenum query, GLint *v ) {
        glGetMapiv(target, query, v);
 }

static void AmiglEvalCoord1d( GLdouble u ) {
        glEvalCoord1d(u);
 }
static void AmiglEvalCoord1f( GLfloat u ) {
        glEvalCoord1f(u);
 }

static void AmiglEvalCoord1dv( const GLdouble *u ) {
        glEvalCoord1dv(u);
 }
static void AmiglEvalCoord1fv( const GLfloat *u ) {
        glEvalCoord1fv(u);
 }

static void AmiglEvalCoord2d( GLdouble u, GLdouble v ) {
        glEvalCoord2d(u, v);
 }
static void AmiglEvalCoord2f( GLfloat u, GLfloat v ) {
        glEvalCoord2f(u, v);
 }

static void AmiglEvalCoord2dv( const GLdouble *u ) {
        glEvalCoord2dv(u);
 }
static void AmiglEvalCoord2fv( const GLfloat *u ) {
        glEvalCoord2fv(u);
 }

static void AmiglMapGrid1d( GLint un, GLdouble u1, GLdouble u2 ) {
        glMapGrid1d(un, u1, u2);
 }
static void AmiglMapGrid1f( GLint un, GLfloat u1, GLfloat u2 ) {
        glMapGrid1f(un, u1, u2);
 }

static void AmiglMapGrid2d( GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2 ) {
        glMapGrid2d(un, u1, u2, vn, v1, v2);
 }
static void AmiglMapGrid2f( GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2 ) {
        glMapGrid2f(un, u1, u2, vn, v1, v2);
 }

static void AmiglEvalPoint1( GLint i ) {
        glEvalPoint1(i);
 }

static void AmiglEvalPoint2( GLint i, GLint j ) {
        glEvalPoint2(i, j);
 }

static void AmiglEvalMesh1( GLenum mode, GLint i1, GLint i2 ) {
        glEvalMesh1(mode, i1, i2);
 }

static void AmiglEvalMesh2( GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2 ) {
        glEvalMesh2(mode, i1, i2, j1, j2);
 }

/*
 * Fog
 */

static void AmiglFogf( GLenum pname, GLfloat param ) {
        glFogf(pname, param);
 }

static void AmiglFogi( GLenum pname, GLint param ) {
        glFogi(pname, param);
 }

static void AmiglFogfv( GLenum pname, GLfloat *params ) {
        glFogfv(pname, params);
 }

static void AmiglFogiv( GLenum pname, const GLint *params ) {
#ifndef __amigaos4__
        glFogiv(pname, params);
#endif
 }

/*
 * Selection and Feedback
 */

static void AmiglFeedbackBuffer( GLsizei size, GLenum type, GLfloat *buffer ) {
#ifndef __amigaos4__
        glFeedbackBuffer(size, type, buffer);
#endif
 }

static void AmiglPassThrough( GLfloat token ) {
#ifndef __amigaos4__
        glPassThrough(token);
#endif
 }

static void AmiglSelectBuffer( GLsizei size, GLuint *buffer ) {
        glSelectBuffer(size, buffer);
 }

static void AmiglInitNames( void ) {
        glInitNames();
 }

static void AmiglLoadName( GLuint name ) {
        glLoadName(name);
 }

static void AmiglPushName( GLuint name ) {
        glPushName(name);
 }

static void AmiglPopName( void ) {
        glPopName();
 }

/*
 * 1.0 Extensions
 */

/* GL_EXT_blend_minmax */
static void AmiglBlendEquationEXT( GLenum mode ) {
#ifndef __amigaos4__
        glBlendEquationEXT(mode);
#endif
 }

/* GL_EXT_blend_color */
static void AmiglBlendColorEXT( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha ) {
#ifndef __amigaos4__
        glBlendColorEXT(red, green, blue, alpha);
#endif
 }

/* GL_EXT_polygon_offset */
static void AmiglPolygonOffsetEXT( GLfloat factor, GLfloat bias ) {
#ifndef __amigaos4__
        glPolygonOffsetEXT(factor, bias);
#endif
 }

/* GL_EXT_vertex_array */

static void AmiglVertexPointerEXT( GLint size, GLenum type,
                        GLsizei stride,
                        GLsizei count, const GLvoid *ptr ) {
#ifndef __amigaos4__
        glVertexPointerEXT(size, type, stride, count, ptr);
#endif
 }

static void AmiglNormalPointerEXT( GLenum type, GLsizei stride,
                        GLsizei count, const GLvoid *ptr ) {
#ifndef __amigaos4__
        glNormalPointerEXT(type, stride, count, ptr);
#endif
 }

static void AmiglColorPointerEXT( GLint size, GLenum type,
                       GLsizei stride,
                       GLsizei count, const GLvoid *ptr ) {
#ifndef __amigaos4__
        glColorPointerEXT(size, type, stride, count, ptr);
#endif
 }

static void AmiglIndexPointerEXT( GLenum type, GLsizei stride,
                       GLsizei count, const GLvoid *ptr ) {
#ifndef __amigaos4__
        glIndexPointerEXT(type, stride, count, ptr);
#endif
 }

static void AmiglTexCoordPointerEXT( GLint size, GLenum type,
                          GLsizei stride, GLsizei count,
                          const GLvoid *ptr ) {
#ifndef __amigaos4__
        glTexCoordPointerEXT(size, type, stride, count, ptr);
#endif
 }

static void AmiglEdgeFlagPointerEXT( GLsizei stride, GLsizei count, const GLboolean *ptr ) {
#ifndef __amigaos4__
        glEdgeFlagPointerEXT(stride, count, ptr);
#endif
 }

static void AmiglGetPointervEXT( GLenum pname, void **params ) {
#ifndef __amigaos4__
        glGetPointervEXT(pname, params);
#endif
 }

static void AmiglArrayElementEXT( GLint i ) {
#ifndef __amigaos4__
        glArrayElementEXT(i);
#endif
 }

static void AmiglDrawArraysEXT( GLenum mode, GLint first, GLsizei count ) {
#ifndef __amigaos4__
        glDrawArraysEXT(mode, first, count);
#endif
 }

/* GL_EXT_texture_object */

static void AmiglGenTexturesEXT( GLsizei n, GLuint *textures ) {
#ifndef __amigaos4__
        glGenTexturesEXT(n, textures);
#endif
 }

static void AmiglDeleteTexturesEXT( GLsizei n, const GLuint *textures) {
#ifndef __amigaos4__
        glDeleteTexturesEXT(n, textures);
#endif
 }

static void AmiglBindTextureEXT( GLenum target, GLuint texture ) {
#ifndef __amigaos4__
        glBindTextureEXT(target, texture);
#endif
 }

static void AmiglPrioritizeTexturesEXT( GLsizei n, const GLuint *textures, const GLclampf *priorities ) {
#ifndef __amigaos4__
        glPrioritizeTexturesEXT(n, textures, priorities);
#endif
 }

 GLboolean AmiglAreTexturesResidentEXT( GLsizei n, const GLuint *textures, GLboolean *residences ) {
#ifndef __amigaos4__
        return glAreTexturesResidentEXT(n, textures, residences);
#else
    return 0;
#endif
 }

 GLboolean AmiglIsTextureEXT( GLuint texture ) {
#ifndef __amigaos4__
        return glIsTextureEXT(texture);
#else
    return 0;
#endif
 }

/* GL_EXT_texture3D */

static void AmiglTexImage3DEXT( GLenum target, GLint level,
                     GLenum internalFormat,
                     GLsizei width, GLsizei height,
                     GLsizei depth, GLint border,
                     GLenum format, GLenum type,
                     const GLvoid *pixels ) {
#ifndef __amigaos4__
        glTexImage3DEXT(target, level, internalFormat, width, height, depth, border,
                             format, type, pixels);
#endif
 }

static void AmiglTexSubImage3DEXT( GLenum target, GLint level,
                        GLint xoffset, GLint yoffset,
                        GLint zoffset, GLsizei width,
                        GLsizei height, GLsizei depth,
                        GLenum format,
                        GLenum type, const GLvoid *pixels) {
#ifndef __amigaos4__
        glTexSubImage3DEXT(target, level, xoffset, yoffset, zoffset,
                                 width, height, depth, format, type, pixels);
#endif
 }

static void AmiglCopyTexSubImage3DEXT( GLenum target, GLint level,
                        GLint xoffset, GLint yoffset,
                        GLint zoffset, GLint x,
                        GLint y, GLsizei width,
                        GLsizei height ) {
#ifndef __amigaos4__
        glCopyTexSubImage3DEXT(target, level, xoffset, yoffset, zoffset,
                                      x, y, width, height);
#endif
 }

/* GL_EXT_color_table */

static void AmiglColorTableEXT( GLenum target, GLenum internalformat,
                     GLsizei width, GLenum format,
                     GLenum type, const GLvoid *table ) {
#ifndef __amigaos4__
        glColorTableEXT(target, internalformat, width, format, type, table);
#endif
 }

static void AmiglColorSubTableEXT( GLenum target,
                        GLsizei start, GLsizei count,
                        GLenum format, GLenum type,
                        const GLvoid *data ) {
#ifndef __amigaos4__
        glColorSubTableEXT(target, start, count, format, type, data);
#endif
 }

static void AmiglGetColorTableEXT( GLenum target, GLenum format,
                        GLenum type, GLvoid *table ) {
#ifndef __amigaos4__
        glGetColorTableEXT(target, format, type, table);
#endif
 }

static void AmiglGetColorTableParameterfvEXT( GLenum target,
                               GLenum pname,
                               GLfloat *params ) {
#ifndef __amigaos4__
        glGetColorTableParameterfvEXT(target, pname, params);
#endif
 }

static void AmiglGetColorTableParameterivEXT( GLenum target,
                               GLenum pname,
                               GLint *params ) {
#ifndef __amigaos4__
        glGetColorTableParameterivEXT(target, pname, params);
#endif
 }

/* GL_SGIS_multitexture */

static void AmiglMultiTexCoord1dSGIS(GLenum target, GLdouble s) {
#ifndef __amigaos4__
       glMultiTexCoord1dSGIS(target, s);
#endif
 }
static void AmiglMultiTexCoord1dvSGIS(GLenum target, const GLdouble *v) {
#ifndef __amigaos4__
        glMultiTexCoord1dvSGIS(target, v);
#endif
 }
static void AmiglMultiTexCoord1fSGIS(GLenum target, GLfloat s) {
#ifndef __amigaos4__
        glMultiTexCoord1fSGIS(target, s);
#endif
 }
static void AmiglMultiTexCoord1fvSGIS(GLenum target, const GLfloat *v) {
#ifndef __amigaos4__
        glMultiTexCoord1fvSGIS(target, v);
#endif
 }
static void AmiglMultiTexCoord1iSGIS(GLenum target, GLint s) {
#ifndef __amigaos4__
        glMultiTexCoord1iSGIS(target, s);
#endif
 }
static void AmiglMultiTexCoord1ivSGIS(GLenum target, const GLint *v) {
#ifndef __amigaos4__
        glMultiTexCoord1ivSGIS(target, v);
#endif
 }
static void AmiglMultiTexCoord1sSGIS(GLenum target, GLshort s) {
#ifndef __amigaos4__
        glMultiTexCoord1sSGIS(target, s);
#endif
 }
static void AmiglMultiTexCoord1svSGIS(GLenum target, const GLshort *v) {
#ifndef __amigaos4__
        glMultiTexCoord1svSGIS(target, v);
#endif
 }
static void AmiglMultiTexCoord2dSGIS(GLenum target, GLdouble s, GLdouble t) {
#ifndef __amigaos4__
        glMultiTexCoord2dSGIS(target, s, t);
#endif
 }
static void AmiglMultiTexCoord2dvSGIS(GLenum target, const GLdouble *v) {
#ifndef __amigaos4__
        glMultiTexCoord2dvSGIS(target, v);
#endif
 }
static void AmiglMultiTexCoord2fSGIS(GLenum target, GLfloat s, GLfloat t) {
#ifndef __amigaos4__
        glMultiTexCoord2fSGIS(target, s, t);
#endif
 }
static void AmiglMultiTexCoord2fvSGIS(GLenum target, const GLfloat *v) {
#ifndef __amigaos4__
        glMultiTexCoord2fvSGIS(target, v);
#endif
 }
static void AmiglMultiTexCoord2iSGIS(GLenum target, GLint s, GLint t) {
#ifndef __amigaos4__
        glMultiTexCoord2iSGIS(target, s, t);
#endif
 }
static void AmiglMultiTexCoord2ivSGIS(GLenum target, const GLint *v) {
#ifndef __amigaos4__
        glMultiTexCoord2ivSGIS(target, v);
#endif
 }
static void AmiglMultiTexCoord2sSGIS(GLenum target, GLshort s, GLshort t) {
#ifndef __amigaos4__
        glMultiTexCoord2sSGIS(target, s, t);
#endif
 }
static void AmiglMultiTexCoord2svSGIS(GLenum target, const GLshort *v) {
#ifndef __amigaos4__
        glMultiTexCoord2svSGIS(target, v);
#endif
 }
static void AmiglMultiTexCoord3dSGIS(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
#ifndef __amigaos4__
        glMultiTexCoord3dSGIS(target, s, t, r);
#endif
 }
static void AmiglMultiTexCoord3dvSGIS(GLenum target, const GLdouble *v) {
#ifndef __amigaos4__
        glMultiTexCoord3dvSGIS(target, v);
#endif
 }
static void AmiglMultiTexCoord3fSGIS(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
#ifndef __amigaos4__
        glMultiTexCoord3fSGIS(target, s, t, r);
#endif
 }
static void AmiglMultiTexCoord3fvSGIS(GLenum target, const GLfloat *v) {
#ifndef __amigaos4__
        glMultiTexCoord3fvSGIS(target, v);
#endif
 }
static void AmiglMultiTexCoord3iSGIS(GLenum target, GLint s, GLint t, GLint r) {
#ifndef __amigaos4__
        glMultiTexCoord3iSGIS(target, s, t, r);
#endif
 }
static void AmiglMultiTexCoord3ivSGIS(GLenum target, const GLint *v) {
#ifndef __amigaos4__
        glMultiTexCoord3ivSGIS(target, v);
#endif
 }
static void AmiglMultiTexCoord3sSGIS(GLenum target, GLshort s, GLshort t, GLshort r) {
#ifndef __amigaos4__
        glMultiTexCoord3sSGIS(target, s, t, r);
#endif
 }
static void AmiglMultiTexCoord3svSGIS(GLenum target, const GLshort *v) {
#ifndef __amigaos4__
        glMultiTexCoord3svSGIS(target, v);
#endif
 }
static void AmiglMultiTexCoord4dSGIS(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
#ifndef __amigaos4__
        glMultiTexCoord4dSGIS(target, s, t, r, q);
#endif
 }
static void AmiglMultiTexCoord4dvSGIS(GLenum target, const GLdouble *v) {
#ifndef __amigaos4__
        glMultiTexCoord4dvSGIS(target, v);
#endif
 }
static void AmiglMultiTexCoord4fSGIS(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
#ifndef __amigaos4__
        glMultiTexCoord4fSGIS(target, s, t, r, q);
#endif
 }
static void AmiglMultiTexCoord4fvSGIS(GLenum target, const GLfloat *v) {
#ifndef __amigaos4__
        glMultiTexCoord4fvSGIS(target, v);
#endif
 }
static void AmiglMultiTexCoord4iSGIS(GLenum target, GLint s, GLint t, GLint r, GLint q) {
#ifndef __amigaos4__
        glMultiTexCoord4iSGIS(target, s, t, r, q);
#endif
 }
static void AmiglMultiTexCoord4ivSGIS(GLenum target, const GLint *v) {
#ifndef __amigaos4__
        glMultiTexCoord4ivSGIS(target, v);
#endif
 }
static void AmiglMultiTexCoord4sSGIS(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
#ifndef __amigaos4__
        glMultiTexCoord4sSGIS(target, s, t, r, q);
#endif
 }
static void AmiglMultiTexCoord4svSGIS(GLenum target, const GLshort *v) {
#ifndef __amigaos4__
        glMultiTexCoord4svSGIS(target, v);
#endif
 }

static void AmiglMultiTexCoordPointerSGIS(GLenum target, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
#ifndef __amigaos4__
        glMultiTexCoordPointerSGIS(target, size, type, stride, pointer);
#endif
 }

static void AmiglSelectTextureSGIS(GLenum target) {
#ifndef __amigaos4__
        glSelectTextureSGIS(target);
#endif
 }

static void AmiglSelectTextureCoordSetSGIS(GLenum target) {
#ifndef __amigaos4__
        glSelectTextureCoordSetSGIS(target);
#endif
 }

/* GL_EXT_multitexture */

static void AmiglMultiTexCoord1dEXT(GLenum target, GLdouble s) {
#ifndef __amigaos4__
        glMultiTexCoord1dEXT(target, s);
#endif
 }
static void AmiglMultiTexCoord1dvEXT(GLenum target, const GLdouble *v) {
#ifndef __amigaos4__
        glMultiTexCoord1dvEXT(target, v);
#endif
 }
static void AmiglMultiTexCoord1fEXT(GLenum target, GLfloat s) {
#ifndef __amigaos4__
        glMultiTexCoord1fEXT(target, s);
#endif
 }
static void AmiglMultiTexCoord1fvEXT(GLenum target, const GLfloat *v) {
#ifndef __amigaos4__
        glMultiTexCoord1fvEXT(target, v);
#endif
 }
static void AmiglMultiTexCoord1iEXT(GLenum target, GLint s) {
#ifndef __amigaos4__
        glMultiTexCoord1iEXT(target, s);
#endif
 }
static void AmiglMultiTexCoord1ivEXT(GLenum target, const GLint *v) {
#ifndef __amigaos4__
        glMultiTexCoord1ivEXT(target, v);
#endif
 }
static void AmiglMultiTexCoord1sEXT(GLenum target, GLshort s) {
#ifndef __amigaos4__
        glMultiTexCoord1sEXT(target, s);
#endif
 }
static void AmiglMultiTexCoord1svEXT(GLenum target, const GLshort *v) {
#ifndef __amigaos4__
        glMultiTexCoord1svEXT(target, v);
#endif
 }
static void AmiglMultiTexCoord2dEXT(GLenum target, GLdouble s, GLdouble t) {
#ifndef __amigaos4__
        glMultiTexCoord2dEXT(target, s, t);
#endif
 }
static void AmiglMultiTexCoord2dvEXT(GLenum target, const GLdouble *v) {
#ifndef __amigaos4__
        glMultiTexCoord2dvEXT(target, v);
#endif
 }
static void AmiglMultiTexCoord2fEXT(GLenum target, GLfloat s, GLfloat t) {
#ifndef __amigaos4__
        glMultiTexCoord2fEXT(target, s, t);
#endif
 }
static void AmiglMultiTexCoord2fvEXT(GLenum target, const GLfloat *v) {
#ifndef __amigaos4__
        glMultiTexCoord2fvEXT(target, v);
#endif
 }
static void AmiglMultiTexCoord2iEXT(GLenum target, GLint s, GLint t) {
#ifndef __amigaos4__
        glMultiTexCoord2iEXT(target, s, t);
#endif
 }
static void AmiglMultiTexCoord2ivEXT(GLenum target, const GLint *v) {
#ifndef __amigaos4__
        glMultiTexCoord2ivEXT(target, v);
#endif
 }
static void AmiglMultiTexCoord2sEXT(GLenum target, GLshort s, GLshort t) {
#ifndef __amigaos4__
        glMultiTexCoord2sEXT(target, s, t);
#endif
 }
static void AmiglMultiTexCoord2svEXT(GLenum target, const GLshort *v) {
#ifndef __amigaos4__
        glMultiTexCoord2svEXT(target, v);
#endif
 }
static void AmiglMultiTexCoord3dEXT(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
#ifndef __amigaos4__
        glMultiTexCoord3dEXT(target, s, t, r);
#endif
 }
static void AmiglMultiTexCoord3dvEXT(GLenum target, const GLdouble *v) {
#ifndef __amigaos4__
        glMultiTexCoord3dvEXT(target, v);
#endif
 }
static void AmiglMultiTexCoord3fEXT(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
#ifndef __amigaos4__
        glMultiTexCoord3fEXT(target, s, t, r);
#endif
 }
static void AmiglMultiTexCoord3fvEXT(GLenum target, const GLfloat *v) {
#ifndef __amigaos4__
        glMultiTexCoord3fvEXT(target, v);
#endif
 }
static void AmiglMultiTexCoord3iEXT(GLenum target, GLint s, GLint t, GLint r) {
#ifndef __amigaos4__
        glMultiTexCoord3iEXT(target, s, t, r);
#endif
 }
static void AmiglMultiTexCoord3ivEXT(GLenum target, const GLint *v) {
#ifndef __amigaos4__
        glMultiTexCoord3ivEXT(target, v);
#endif
 }
static void AmiglMultiTexCoord3sEXT(GLenum target, GLshort s, GLshort t, GLshort r) {
#ifndef __amigaos4__
        glMultiTexCoord3sEXT(target, s, t, r);
#endif
 }
static void AmiglMultiTexCoord3svEXT(GLenum target, const GLshort *v) {
#ifndef __amigaos4__
        glMultiTexCoord3svEXT(target, v);
#endif
 }
static void AmiglMultiTexCoord4dEXT(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
#ifndef __amigaos4__
        glMultiTexCoord4dEXT(target, s, t, r, q);
#endif
 }
static void AmiglMultiTexCoord4dvEXT(GLenum target, const GLdouble *v) {
#ifndef __amigaos4__
        glMultiTexCoord4dvEXT(target, v);
#endif
 }
static void AmiglMultiTexCoord4fEXT(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
#ifndef __amigaos4__
        glMultiTexCoord4fEXT(target, s, t, r, q);
#endif
 }
static void AmiglMultiTexCoord4fvEXT(GLenum target, const GLfloat *v) {
#ifndef __amigaos4__
        glMultiTexCoord4fvEXT(target, v);
#endif
 }
static void AmiglMultiTexCoord4iEXT(GLenum target, GLint s, GLint t, GLint r, GLint q) {
#ifndef __amigaos4__
        glMultiTexCoord4iEXT(target, s, t, r, q);
#endif
 }
static void AmiglMultiTexCoord4ivEXT(GLenum target, const GLint *v) {
#ifndef __amigaos4__
        glMultiTexCoord4ivEXT(target, v);
#endif
 }
static void AmiglMultiTexCoord4sEXT(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
#ifndef __amigaos4__
        glMultiTexCoord4sEXT(target, s, t, r, q);
#endif
 }
static void AmiglMultiTexCoord4svEXT(GLenum target, const GLshort *v) {
#ifndef __amigaos4__
        glMultiTexCoord4svEXT(target, v);
#endif
 }
static void AmiglInterleavedTextureCoordSetsEXT( GLint factor ) {
#ifndef __amigaos4__
        glInterleavedTextureCoordSetsEXT(factor);
#endif
 }

static void AmiglSelectTextureEXT( GLenum target ) {
#ifndef __amigaos4__
        glSelectTextureEXT(target);
#endif
 }

static void AmiglSelectTextureCoordSetEXT( GLenum target ) {
#ifndef __amigaos4__
        glSelectTextureCoordSetEXT(target);
#endif
 }

static void AmiglSelectTextureTransformEXT( GLenum target ) {
#ifndef __amigaos4__
        glSelectTextureTransformEXT(target);
#endif
 }

/* GL_EXT_point_parameters */
static void AmiglPointParameterfEXT( GLenum pname, GLfloat param ) {
#ifndef __amigaos4__
        glPointParameterfEXT(pname, param);
#endif
 }

static void AmiglPointParameterfvEXT( GLenum pname, GLfloat *params ) {
#ifndef __amigaos4__
        glPointParameterfvEXT(pname, params);
#endif
 }

/* GL_MESA_window_pos */

static void AmiglWindowPos2iMESA( GLint x, GLint y ) {
#ifndef __amigaos4__
        glWindowPos2iMESA(x, y);
#endif
 }
static void AmiglWindowPos2sMESA( GLshort x, GLshort y ) {
#ifndef __amigaos4__
        glWindowPos2sMESA(x, y);
#endif
 }
static void AmiglWindowPos2fMESA( GLfloat x, GLfloat y ) {
#ifndef __amigaos4__
        glWindowPos2fMESA(x, y);
#endif
 }
static void AmiglWindowPos2dMESA( GLdouble x, GLdouble y ) {
#ifndef __amigaos4__
        glWindowPos2dMESA(x, y);
#endif
 }
static void AmiglWindowPos2ivMESA( const GLint *p ) {
#ifndef __amigaos4__
        glWindowPos2ivMESA(p);
#endif
 }
static void AmiglWindowPos2svMESA( const GLshort *p ) {
#ifndef __amigaos4__
        glWindowPos2svMESA(p);
#endif
 }
static void AmiglWindowPos2fvMESA( const GLfloat *p ) {
#ifndef __amigaos4__
        glWindowPos2fvMESA(p);
#endif
 }
static void AmiglWindowPos2dvMESA( const GLdouble *p ) {
#ifndef __amigaos4__
        glWindowPos2dvMESA(p);
#endif
 }
static void AmiglWindowPos3iMESA( GLint x, GLint y, GLint z ) {
#ifndef __amigaos4__
        glWindowPos3iMESA(x, y, z);
#endif
 }
static void AmiglWindowPos3sMESA( GLshort x, GLshort y, GLshort z ) {
#ifndef __amigaos4__
        glWindowPos3sMESA(x, y, z);
#endif
 }
static void AmiglWindowPos3fMESA( GLfloat x, GLfloat y, GLfloat z ) {
#ifndef __amigaos4__
        glWindowPos3fMESA(x, y, z);
#endif
 }
static void AmiglWindowPos3dMESA( GLdouble x, GLdouble y, GLdouble z ) {
#ifndef __amigaos4__
        glWindowPos3dMESA(x, y, z);
#endif
 }
static void AmiglWindowPos3ivMESA( const GLint *p ) {
#ifndef __amigaos4__
        glWindowPos3ivMESA(p);
#endif
 }
static void AmiglWindowPos3svMESA( const GLshort *p ) {
#ifndef __amigaos4__
        glWindowPos3svMESA(p);
#endif
 }
static void AmiglWindowPos3fvMESA( const GLfloat *p ) {
#ifndef __amigaos4__
        glWindowPos3fvMESA(p);
#endif
 }
static void AmiglWindowPos3dvMESA( const GLdouble *p ) {
#ifndef __amigaos4__
        glWindowPos3dvMESA(p);
#endif
 }
static void AmiglWindowPos4iMESA( GLint x, GLint y, GLint z, GLint w ) {
#ifndef __amigaos4__
        glWindowPos4iMESA(x, y, z, w);
#endif
 }
static void AmiglWindowPos4sMESA( GLshort x, GLshort y, GLshort z, GLshort w ) {
#ifndef __amigaos4__
        glWindowPos4sMESA(x, y, z, w);
#endif
 }
static void AmiglWindowPos4fMESA( GLfloat x, GLfloat y, GLfloat z, GLfloat w ) {
#ifndef __amigaos4__
        glWindowPos4fMESA(x, y, z, w);
#endif
 }
static void AmiglWindowPos4dMESA( GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
#ifndef __amigaos4__
        glWindowPos4dMESA(x, y, z, w);
#endif
 }
static void AmiglWindowPos4ivMESA( const GLint *p ) {
#ifndef __amigaos4__
        glWindowPos4ivMESA(p);
#endif
 }
static void AmiglWindowPos4svMESA( const GLshort *p ) {
#ifndef __amigaos4__
        glWindowPos4svMESA(p);
#endif
 }
static void AmiglWindowPos4fvMESA( const GLfloat *p ) {
#ifndef __amigaos4__
        glWindowPos4fvMESA(p);
#endif
 }
static void AmiglWindowPos4dvMESA( const GLdouble *p ) {
#ifndef __amigaos4__
        glWindowPos4dvMESA(p);
#endif
 }

/* GL_MESA_resize_buffers */

static void AmiglResizeBuffersMESA( void ) {
#ifndef __amigaos4__
        glResizeBuffersMESA();
#endif
 }

/* 1.2 functions */
static void AmiglDrawRangeElements( GLenum mode, GLuint start,
    GLuint end, GLsizei count, GLenum type, const GLvoid *indices ) {
        glDrawRangeElements(mode, start, end, count, type, indices);
 }

static void AmiglTexImage3D( GLenum target, GLint level,
                      GLenum internalFormat,
                      GLsizei width, GLsizei height,
                      GLsizei depth, GLint border,
                      GLenum format, GLenum type,
                      const GLvoid *pixels ) {
#ifndef __amigaos4__
        glTexImage3D(target, level, internalFormat, width, height, depth,
                         border, format, type, pixels);
#endif
 }

static void AmiglTexSubImage3D( GLenum target, GLint level,
                     GLint xoffset, GLint yoffset,
                     GLint zoffset, GLsizei width,
                     GLsizei height, GLsizei depth,
                     GLenum format,
                     GLenum type, const GLvoid *pixels) {
#ifndef __amigaos4__
        glTexSubImage3D(target, level, xoffset, yoffset, zoffset,
                             width, height, depth, format, type, pixels);
#endif
 }

static void AmiglCopyTexSubImage3D( GLenum target, GLint level,
                         GLint xoffset, GLint yoffset,
                         GLint zoffset, GLint x,
                         GLint y, GLsizei width,
                         GLsizei height ) {
#ifndef __amigaos4__
        glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
#endif
 }

/* GL_EXT_compiled_vertex_array */

static void AmiglLockArraysEXT( GLint first, GLint count ) {
        glLockArraysEXT(first, count);
}

static void AmiglUnlockArraysEXT( void ) {
        glUnlockArraysEXT();
}

/* The GLU API */

/*
 *
 * Miscellaneous functions
 *
 * These functions are in libGLU.a but require constructor handling... so these are left out.
 */

#ifndef __amigaos4__
static void AmigluLookAt( GLdouble eyex, GLdouble eyey, GLdouble eyez,
                                GLdouble centerx, GLdouble centery,
                                GLdouble centerz,
                                GLdouble upx, GLdouble upy, GLdouble upz ) {

        gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
 }

static void AmigluOrtho2D( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top ) {
        gluOrtho2D(left, right, bottom, top);
 }

static void AmigluPerspective( GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar ) {
        gluPerspective(fovy, aspect, zNear, zFar);
 }

void AmigluPickMatrix( GLdouble x, GLdouble y, GLdouble width, GLdouble height, const GLint viewport[4] )
{
        gluPickMatrix(x, y, width, height, (GLint *)viewport);
}

 GLint AmigluProject( GLdouble objx, GLdouble objy, GLdouble objz,
                                  const GLdouble modelMatrix[16],
                                  const GLdouble projMatrix[16],
                                  const GLint viewport[4],
                                  GLdouble *winx, GLdouble *winy,
                                  GLdouble *winz )
{
   return gluProject(objx, objy, objz, modelMatrix, projMatrix, viewport, winx, winy, winz);
}

 GLint AmigluUnProject( GLdouble winx, GLdouble winy,
                                    GLdouble winz,
                                    const GLdouble modelMatrix[16],
                                    const GLdouble projMatrix[16],
                                    const GLint viewport[4],
                                    GLdouble *objx, GLdouble *objy,
                                    GLdouble *objz ) {

        return gluUnProject(winx, winy, winz, modelMatrix, projMatrix, viewport, objx, objy, objz);
 }

static const GLubyte* AmigluErrorString( GLenum errorCode ) {
#ifndef __amigaos4__
        return gluErrorString(errorCode);
#else
    return NULL;
#endif
 }

/*
 *
 * Mipmapping and image scaling
 *
 */

 GLint AmigluScaleImage( GLenum format,
                                     GLint widthin, GLint heightin,
                                     GLenum typein, const void *datain,
                                     GLint widthout, GLint heightout,
                                     GLenum typeout, void *dataout ) {
        return gluScaleImage(format, widthin, heightin, typein, datain, widthout, heightout, typeout, dataout);
 }

 GLint AmigluBuild1DMipmaps( GLenum target, GLint components,
                                         GLint width, GLenum format,
                                         GLenum type, const void *data ) {
#ifndef __amigaos4__
        return gluBuild1DMipmaps(target, components, width, format, type, data);
#else
    return 0;
#endif
 }

 GLint AmigluBuild2DMipmaps( GLenum target, GLint components,
                                         GLint width, GLint height,
                                         GLenum format,
                                         GLenum type, void *data ) {

        return gluBuild2DMipmaps(target, components, width, height, format, type, data);
 }

/*
 *
 * Quadrics
 *
 */

 GLUquadricObj* AmigluNewQuadric( void ) {
        return gluNewQuadric();
 }

static void AmigluDeleteQuadric( GLUquadricObj *state ) {
        gluDeleteQuadric(state);
 }

static void AmigluQuadricDrawStyle( GLUquadricObj *quadObject, GLenum drawStyle ) {
        gluQuadricDrawStyle(quadObject, drawStyle);
 }

static void AmigluQuadricOrientation( GLUquadricObj *quadObject, GLenum orientation ) {
        gluQuadricOrientation(quadObject, orientation);
 }

static void AmigluQuadricNormals( GLUquadricObj *quadObject, GLenum normals ) {
        gluQuadricNormals(quadObject, normals);
 }

static void AmigluQuadricTexture( GLUquadricObj *quadObject, GLboolean textureCoords ) {
        gluQuadricTexture(quadObject, textureCoords);
 }

/*
static void AmigluQuadricCallback( GLUquadricObj *qobj, GLenum which, void (CALLBACK *fn)() ) {
        gluQuadricCallback(qobj, which, fn);
 }
*/
static void AmigluQuadricCallback( GLUquadricObj *qobj, GLenum which, void *fn) {
        gluQuadricCallback(qobj, which, fn);
 }

static void AmigluCylinder( GLUquadricObj *qobj,
                                  GLdouble baseRadius,
                                  GLdouble topRadius,
                                  GLdouble height,
                                  GLint slices, GLint stacks ) {
        gluCylinder(qobj, baseRadius, topRadius, height, slices, stacks);
 }

static void AmigluSphere( GLUquadricObj *qobj, GLdouble radius, GLint slices, GLint stacks ) {
        gluSphere(qobj, radius, slices, stacks);
 }

static void AmigluDisk( GLUquadricObj *qobj,
                              GLdouble innerRadius, GLdouble outerRadius,
                              GLint slices, GLint loops ) {
        gluDisk(qobj, innerRadius, outerRadius, slices, loops);
 }

static void AmigluPartialDisk( GLUquadricObj *qobj, GLdouble innerRadius,
                                     GLdouble outerRadius, GLint slices,
                                     GLint loops, GLdouble startAngle,
                                     GLdouble sweepAngle ) {
        gluPartialDisk(qobj, innerRadius, outerRadius, slices, loops, startAngle, sweepAngle);
 }

/*
 *
 * Nurbs
 *
 */

static GLUnurbsObj* AmigluNewNurbsRenderer( void ) {
        return gluNewNurbsRenderer();
 }

static void AmigluDeleteNurbsRenderer( GLUnurbsObj *nobj ) {
        gluDeleteNurbsRenderer(nobj);
 }

static void AmigluLoadSamplingMatrices( GLUnurbsObj *nobj,
                                              const GLfloat modelMatrix[16],
                                              const GLfloat projMatrix[16],
                                              const GLint viewport[4] ) {
        gluLoadSamplingMatrices(nobj, modelMatrix, projMatrix, viewport);
 }

static void AmigluNurbsProperty( GLUnurbsObj *nobj, GLenum property, GLfloat value ) {
        gluNurbsProperty(nobj, property, value);
 }

static void AmigluGetNurbsProperty( GLUnurbsObj *nobj, GLenum property, GLfloat *value )
{
	gluGetNurbsProperty(nobj, property, value);
}

static void AmigluBeginCurve( GLUnurbsObj *nobj )
{
	gluBeginCurve(nobj);
}

static void AmigluEndCurve( GLUnurbsObj * nobj )
{
	gluEndCurve(nobj);
}

static void AmigluNurbsCurve( GLUnurbsObj *nobj, GLint nknots,
                                    GLfloat *knot, GLint stride,
                                    GLfloat *ctlarray, GLint order,
                                    GLenum type )
{
        gluNurbsCurve(nobj, nknots, knot, stride, ctlarray, order, type);
}

static void AmigluBeginSurface( GLUnurbsObj *nobj )
{
	gluBeginSurface(nobj);
}

static void AmigluEndSurface( GLUnurbsObj * nobj )
{
	gluEndSurface(nobj);
}

static void AmigluNurbsSurface( GLUnurbsObj *nobj,
                                      GLint sknot_count, GLfloat *sknot,
                                      GLint tknot_count, GLfloat *tknot,
                                      GLint s_stride, GLint t_stride,
                                      GLfloat *ctlarray,
                                      GLint sorder, GLint torder,
                                      GLenum type )
{
	gluNurbsSurface(nobj, sknot_count, sknot, tknot_count, tknot, s_stride, t_stride, ctlarray, sorder, torder, type);
}

static void AmigluBeginTrim( GLUnurbsObj *nobj )
{
	gluBeginTrim(nobj);
}

static void AmigluEndTrim( GLUnurbsObj *nobj )
{
	gluEndTrim(nobj);
}

static void AmigluPwlCurve( GLUnurbsObj *nobj, GLint count, GLfloat *array, GLint stride, GLenum type ) {
	gluPwlCurve(nobj, count, array, stride, type);
 }

static void AmigluNurbsCallback( GLUnurbsObj *nobj, GLenum which, void *fn )
{
	gluNurbsCallback(nobj, which, fn);
}

/*
 *
 * Polygon tesselation
 *
 */

 GLUtriangulatorObj* AmigluNewTess( void ) {
        return gluNewTess();
 }

/*
static void AmigluTessCallback( GLUtriangulatorObj *tobj, GLenum which, void (CALLBACK *fn)() ) {
        gluTessCallback(tobj, which, fn);
 }
*/
static void AmigluTessCallback( GLUtriangulatorObj *tobj, GLenum which, void *fn ) {
        gluTessCallback(tobj, which, fn);
 }

static void AmigluDeleteTess( GLUtriangulatorObj *tobj ) {
        gluDeleteTess(tobj);
 }

static void AmigluBeginPolygon( GLUtriangulatorObj *tobj ) {
        gluBeginPolygon(tobj);
 }

static void AmigluEndPolygon( GLUtriangulatorObj *tobj ) {
        gluEndPolygon(tobj);
 }

static void AmigluNextContour( GLUtriangulatorObj *tobj, GLenum type ) {
        gluNextContour(tobj, type);
 }

static void AmigluTessVertex( GLUtriangulatorObj *tobj, GLdouble v[3], void *data ) {
        gluTessVertex(tobj, v, data);
 }

/*
 *
 * New functions in GLU 1.1
 *
 */

static const GLubyte* AmigluGetString( GLenum name )
{
	return gluGetString(name);
}
#endif

struct MyGLFunc
{
   CONST_STRPTR name;
   APTR func;
};

void *AmiGetGLProc(const char *proc)
{
   static CONST struct MyGLFunc table[] =
   {
     { "glClearColor", AmiglClearColor },
     { "glClear", AmiglClear },
     { "glIndexMask", AmiglIndexMask },
     { "glColorMask", AmiglColorMask },
     { "glAlphaFunc", AmiglAlphaFunc },
     { "glBlendFunc", AmiglBlendFunc },
     { "glLogicOp", AmiglLogicOp },
     { "glCullFace", AmiglCullFace },
     { "glFrontFace", AmiglFrontFace },
     { "glPointSize", AmiglPointSize },
     { "glLineWidth", AmiglLineWidth },
     { "glLineStipple", AmiglLineStipple },
     { "glPolygonMode", AmiglPolygonMode },
     { "glPolygonOffset", AmiglPolygonOffset },
     { "glPolygonStipple", AmiglPolygonStipple },
     { "glGetPolygonStipple", AmiglGetPolygonStipple },
     { "glEdgeFlag", AmiglEdgeFlag },
     { "glEdgeFlagv", AmiglEdgeFlagv },
     { "glScissor", AmiglScissor },
     { "glClipPlane", AmiglClipPlane },
     { "glGetClipPlane", AmiglGetClipPlane },
     { "glDrawBuffer", AmiglDrawBuffer },
     { "glReadBuffer", AmiglReadBuffer },
     { "glEnable", AmiglEnable },
     { "glDisable", AmiglDisable },
     { "glIsEnabled", AmiglIsEnabled },
     { "glEnableClientState", AmiglEnableClientState },
     { "glDisableClientState", AmiglDisableClientState },
     { "glGetBooleanv", AmiglGetBooleanv },
     { "glGetDoublev", AmiglGetDoublev },
     { "glGetFloatv", AmiglGetFloatv },
     { "glGetIntegerv", AmiglGetIntegerv },
     { "glPushAttrib", AmiglPushAttrib },
     { "glPopAttrib", AmiglPopAttrib },
     { "glPushClientAttrib", AmiglPushClientAttrib },
     { "glPopClientAttrib", AmiglPopClientAttrib },
     { "glRenderMode", AmiglRenderMode },
     { "glGetError", AmiglGetError },
     { "glGetString", AmiglGetString },
     { "glFinish", AmiglFinish },
     { "glFlush", AmiglFlush },
     { "glHint", AmiglHint },
     { "glClearDepth", AmiglClearDepth },
     { "glDepthFunc", AmiglDepthFunc },
     { "glDepthMask", AmiglDepthMask },
     { "glDepthRange", AmiglDepthRange },
	#ifndef __amigaos4__
     { "glClearAccum", AmiglClearAccum },
     { "glAccum", AmiglAccum },
	#endif
     { "glMatrixMode", AmiglMatrixMode },
     { "glOrtho", AmiglOrtho },
     { "glFrustum", AmiglFrustum },
     { "glViewport", AmiglViewport },
     { "glPushMatrix", AmiglPushMatrix },
     { "glPopMatrix", AmiglPopMatrix },
     { "glLoadIdentity", AmiglLoadIdentity },
     { "glLoadMatrixd", AmiglLoadMatrixd },
     { "glLoadMatrixf", AmiglLoadMatrixf },
     { "glMultMatrixd", AmiglMultMatrixd },
     { "glMultMatrixf", AmiglMultMatrixf },
     { "glRotated", AmiglRotated },
     { "glRotatef", AmiglRotatef },
     { "glScaled", AmiglScaled },
     { "glScalef", AmiglScalef },
     { "glTranslated", AmiglTranslated },
     { "glTranslatef", AmiglTranslatef },
     { "glIsList", AmiglIsList },
     { "glDeleteLists", AmiglDeleteLists },
     { "glGenLists", AmiglGenLists },
     { "glNewList", AmiglNewList },
     { "glEndList", AmiglEndList },
     { "glCallList", AmiglCallList },
     { "glCallLists", AmiglCallLists },
     { "glListBase", AmiglListBase },
     { "glBegin", AmiglBegin },
     { "glEnd", AmiglEnd },
     { "glVertex2d", AmiglVertex2d },
     { "glVertex2f", AmiglVertex2f },
     { "glVertex2i", AmiglVertex2i },
     { "glVertex2s", AmiglVertex2s },
     { "glVertex3d", AmiglVertex3d },
     { "glVertex3f", AmiglVertex3f },
     { "glVertex3i", AmiglVertex3i },
     { "glVertex3s", AmiglVertex3s },
     { "glVertex4d", AmiglVertex4d },
     { "glVertex4f", AmiglVertex4f },
     { "glVertex4i", AmiglVertex4i },
     { "glVertex4s", AmiglVertex4s },
     { "glVertex2dv", AmiglVertex2dv },
     { "glVertex2fv", AmiglVertex2fv },
     { "glVertex2iv", AmiglVertex2iv },
     { "glVertex2sv", AmiglVertex2sv },
     { "glVertex3dv", AmiglVertex3dv },
     { "glVertex3fv", AmiglVertex3fv },
     { "glVertex3iv", AmiglVertex3iv },
     { "glVertex3sv", AmiglVertex3sv },
     { "glVertex4dv", AmiglVertex4dv },
     { "glVertex4fv", AmiglVertex4fv },
     { "glVertex4iv", AmiglVertex4iv },
     { "glVertex4sv", AmiglVertex4sv },
     { "glNormal3b", AmiglNormal3b },
     { "glNormal3d", AmiglNormal3d },
     { "glNormal3f", AmiglNormal3f },
     { "glNormal3i", AmiglNormal3i },
     { "glNormal3s", AmiglNormal3s },
     { "glNormal3bv", AmiglNormal3bv },
     { "glNormal3dv", AmiglNormal3dv },
     { "glNormal3fv", AmiglNormal3fv },
     { "glNormal3iv", AmiglNormal3iv },
     { "glNormal3sv", AmiglNormal3sv },
     { "glIndexd", AmiglIndexd },
     { "glIndexf", AmiglIndexf },
     { "glIndexi", AmiglIndexi },
     { "glIndexs", AmiglIndexs },
     { "glIndexub", AmiglIndexub },
     { "glIndexdv", AmiglIndexdv },
     { "glIndexfv", AmiglIndexfv },
     { "glIndexiv", AmiglIndexiv },
     { "glIndexsv", AmiglIndexsv },
     { "glIndexubv", AmiglIndexubv },
     { "glColor3b", AmiglColor3b },
     { "glColor3d", AmiglColor3d },
     { "glColor3f", AmiglColor3f },
     { "glColor3i", AmiglColor3i },
     { "glColor3s", AmiglColor3s },
     { "glColor3ub", AmiglColor3ub },
     { "glColor3ui", AmiglColor3ui },
     { "glColor3us", AmiglColor3us },
     { "glColor4b", AmiglColor4b },
     { "glColor4d", AmiglColor4d },
     { "glColor4f", AmiglColor4f },
     { "glColor4i", AmiglColor4i },
     { "glColor4s", AmiglColor4s },
     { "glColor4ub", AmiglColor4ub },
     { "glColor4ui", AmiglColor4ui },
     { "glColor4us", AmiglColor4us },
     { "glColor3bv", AmiglColor3bv },
     { "glColor3dv", AmiglColor3dv },
     { "glColor3fv", AmiglColor3fv },
     { "glColor3iv", AmiglColor3iv },
     { "glColor3sv", AmiglColor3sv },
     { "glColor3ubv", AmiglColor3ubv },
     { "glColor3uiv", AmiglColor3uiv },
     { "glColor3usv", AmiglColor3usv },
     { "glColor4bv", AmiglColor4bv },
     { "glColor4dv", AmiglColor4dv },
     { "glColor4fv", AmiglColor4fv },
     { "glColor4iv", AmiglColor4iv },
     { "glColor4sv", AmiglColor4sv },
     { "glColor4ubv", AmiglColor4ubv },
     { "glColor4uiv", AmiglColor4uiv },
     { "glColor4usv", AmiglColor4usv },
     { "glTexCoord1d", AmiglTexCoord1d },
     { "glTexCoord1f", AmiglTexCoord1f },
     { "glTexCoord1i", AmiglTexCoord1i },
     { "glTexCoord1s", AmiglTexCoord1s },
     { "glTexCoord2d", AmiglTexCoord2d },
     { "glTexCoord2f", AmiglTexCoord2f },
     { "glTexCoord2i", AmiglTexCoord2i },
     { "glTexCoord2s", AmiglTexCoord2s },
     { "glTexCoord3d", AmiglTexCoord3d },
     { "glTexCoord3f", AmiglTexCoord3f },
     { "glTexCoord3i", AmiglTexCoord3i },
     { "glTexCoord3s", AmiglTexCoord3s },
     { "glTexCoord4d", AmiglTexCoord4d },
     { "glTexCoord4f", AmiglTexCoord4f },
     { "glTexCoord4i", AmiglTexCoord4i },
     { "glTexCoord4s", AmiglTexCoord4s },
     { "glTexCoord1dv", AmiglTexCoord1dv },
     { "glTexCoord1fv", AmiglTexCoord1fv },
     { "glTexCoord1iv", AmiglTexCoord1iv },
     { "glTexCoord1sv", AmiglTexCoord1sv },
     { "glTexCoord2dv", AmiglTexCoord2dv },
     { "glTexCoord2fv", AmiglTexCoord2fv },
     { "glTexCoord2iv", AmiglTexCoord2iv },
     { "glTexCoord2sv", AmiglTexCoord2sv },
     { "glTexCoord3dv", AmiglTexCoord3dv },
     { "glTexCoord3fv", AmiglTexCoord3fv },
     { "glTexCoord3iv", AmiglTexCoord3iv },
     { "glTexCoord3sv", AmiglTexCoord3sv },
     { "glTexCoord4dv", AmiglTexCoord4dv },
     { "glTexCoord4fv", AmiglTexCoord4fv },
     { "glTexCoord4iv", AmiglTexCoord4iv },
     { "glTexCoord4sv", AmiglTexCoord4sv },
     { "glRasterPos2d", AmiglRasterPos2d },
     { "glRasterPos2f", AmiglRasterPos2f },
     { "glRasterPos2i", AmiglRasterPos2i },
     { "glRasterPos2s", AmiglRasterPos2s },
     { "glRasterPos3d", AmiglRasterPos3d },
     { "glRasterPos3f", AmiglRasterPos3f },
     { "glRasterPos3i", AmiglRasterPos3i },
     { "glRasterPos3s", AmiglRasterPos3s },
     { "glRasterPos4d", AmiglRasterPos4d },
     { "glRasterPos4f", AmiglRasterPos4f },
     { "glRasterPos4i", AmiglRasterPos4i },
     { "glRasterPos4s", AmiglRasterPos4s },
     { "glRasterPos2dv", AmiglRasterPos2dv },
     { "glRasterPos2fv", AmiglRasterPos2fv },
     { "glRasterPos2iv", AmiglRasterPos2iv },
     { "glRasterPos2sv", AmiglRasterPos2sv },
     { "glRasterPos3dv", AmiglRasterPos3dv },
     { "glRasterPos3fv", AmiglRasterPos3fv },
     { "glRasterPos3iv", AmiglRasterPos3iv },
     { "glRasterPos3sv", AmiglRasterPos3sv },
     { "glRasterPos4dv", AmiglRasterPos4dv },
     { "glRasterPos4fv", AmiglRasterPos4fv },
     { "glRasterPos4iv", AmiglRasterPos4iv },
     { "glRasterPos4sv", AmiglRasterPos4sv },
     { "glRectd", AmiglRectd },
     { "glRectf", AmiglRectf },
     { "glRecti", AmiglRecti },
     { "glRects", AmiglRects },
     { "glRectdv", AmiglRectdv },
     { "glRectfv", AmiglRectfv },
     { "glRectiv", AmiglRectiv },
     { "glRectsv", AmiglRectsv },
     { "glVertexPointer", AmiglVertexPointer },
     { "glNormalPointer", AmiglNormalPointer },
     { "glColorPointer", AmiglColorPointer },
     { "glIndexPointer", AmiglIndexPointer },
     { "glTexCoordPointer", AmiglTexCoordPointer },
     { "glEdgeFlagPointer", AmiglEdgeFlagPointer },
     { "glGetPointerv", AmiglGetPointerv },
     { "glArrayElement", AmiglArrayElement },
     { "glDrawArrays", AmiglDrawArrays },
     { "glDrawElements", AmiglDrawElements },
     { "glInterleavedArrays", AmiglInterleavedArrays },
     { "glShadeModel", AmiglShadeModel },
     { "glLightf", AmiglLightf },
     { "glLighti", AmiglLighti },
     { "glLightfv", AmiglLightfv },
     { "glLightiv", AmiglLightiv },
     { "glGetLightfv", AmiglGetLightfv },
     { "glGetLightiv", AmiglGetLightiv },
     { "glLightModelf", AmiglLightModelf },
     { "glLightModeli", AmiglLightModeli },
     { "glLightModelfv", AmiglLightModelfv },
     { "glLightModeliv", AmiglLightModeliv },
     { "glMaterialf", AmiglMaterialf },
     { "glMateriali", AmiglMateriali },
     { "glMaterialfv", AmiglMaterialfv },
     { "glMaterialiv", AmiglMaterialiv },
     { "glGetMaterialfv", AmiglGetMaterialfv },
     { "glGetMaterialiv", AmiglGetMaterialiv },
     { "glColorMaterial", AmiglColorMaterial },
     { "glPixelZoom", AmiglPixelZoom },
     { "glPixelStoref", AmiglPixelStoref },
     { "glPixelStorei", AmiglPixelStorei },
     { "glPixelTransferf", AmiglPixelTransferf },
     { "glPixelTransferi", AmiglPixelTransferi },
     { "glPixelMapfv", AmiglPixelMapfv },
     { "glPixelMapuiv", AmiglPixelMapuiv },
     { "glPixelMapusv", AmiglPixelMapusv },
     { "glGetPixelMapfv", AmiglGetPixelMapfv },
     { "glGetPixelMapuiv", AmiglGetPixelMapuiv },
     { "glGetPixelMapusv", AmiglGetPixelMapusv },
     { "glBitmap", AmiglBitmap },
     { "glReadPixels", AmiglReadPixels },
     { "glDrawPixels", AmiglDrawPixels },
     { "glCopyPixels", AmiglCopyPixels },
     { "glStencilFunc", AmiglStencilFunc },
     { "glStencilMask", AmiglStencilMask },
     { "glStencilOp", AmiglStencilOp },
     { "glClearStencil", AmiglClearStencil },
     { "glTexGend", AmiglTexGend },
     { "glTexGenf", AmiglTexGenf },
     { "glTexGeni", AmiglTexGeni },
     { "glTexGendv", AmiglTexGendv },
     { "glTexGenfv", AmiglTexGenfv },
     { "glTexGeniv", AmiglTexGeniv },
     { "glGetTexGendv", AmiglGetTexGendv },
     { "glGetTexGenfv", AmiglGetTexGenfv },
     { "glGetTexGeniv", AmiglGetTexGeniv },
     { "glTexEnvf", AmiglTexEnvf },
     { "glTexEnvi", AmiglTexEnvi },
     { "glTexEnvfv", AmiglTexEnvfv },
     { "glTexEnviv", AmiglTexEnviv },
     { "glGetTexEnvfv", AmiglGetTexEnvfv },
     { "glGetTexEnviv", AmiglGetTexEnviv },
     { "glTexParameterf", AmiglTexParameterf },
     { "glTexParameteri", AmiglTexParameteri },
     { "glTexParameterfv", AmiglTexParameterfv },
     { "glTexParameteriv", AmiglTexParameteriv },
     { "glGetTexParameterfv", AmiglGetTexParameterfv },
     { "glGetTexParameteriv", AmiglGetTexParameteriv },
     { "glGetTexLevelParameterfv", AmiglGetTexLevelParameterfv },
     { "glGetTexLevelParameteriv", AmiglGetTexLevelParameteriv },
     { "glTexImage1D", AmiglTexImage1D },
     { "glTexImage2D", AmiglTexImage2D },
     { "glGetTexImage", AmiglGetTexImage },
     { "glGenTextures", AmiglGenTextures },
     { "glDeleteTextures", AmiglDeleteTextures },
     { "glBindTexture", AmiglBindTexture },
     { "glPrioritizeTextures", AmiglPrioritizeTextures },
     { "glAreTexturesResident", AmiglAreTexturesResident },
     { "glIsTexture", AmiglIsTexture },
     { "glTexSubImage1D", AmiglTexSubImage1D },
     { "glTexSubImage2D", AmiglTexSubImage2D },
     { "glCopyTexImage1D", AmiglCopyTexImage1D },
     { "glCopyTexImage2D", AmiglCopyTexImage2D },
     { "glCopyTexSubImage1D", AmiglCopyTexSubImage1D },
     { "glCopyTexSubImage2D", AmiglCopyTexSubImage2D },
     { "glMap1d", AmiglMap1d },
     { "glMap1f", AmiglMap1f },
     { "glMap2d", AmiglMap2d },
     { "glMap2f", AmiglMap2f },
     { "glGetMapdv", AmiglGetMapdv },
     { "glGetMapfv", AmiglGetMapfv },
     { "glGetMapiv", AmiglGetMapiv },
     { "glEvalCoord1d", AmiglEvalCoord1d },
     { "glEvalCoord1f", AmiglEvalCoord1f },
     { "glEvalCoord1dv", AmiglEvalCoord1dv },
     { "glEvalCoord1fv", AmiglEvalCoord1fv },
     { "glEvalCoord2d", AmiglEvalCoord2d },
     { "glEvalCoord2f", AmiglEvalCoord2f },
     { "glEvalCoord2dv", AmiglEvalCoord2dv },
     { "glEvalCoord2fv", AmiglEvalCoord2fv },
     { "glMapGrid1d", AmiglMapGrid1d },
     { "glMapGrid1f", AmiglMapGrid1f },
     { "glMapGrid2d", AmiglMapGrid2d },
     { "glMapGrid2f", AmiglMapGrid2f },
     { "glEvalPoint1", AmiglEvalPoint1 },
     { "glEvalPoint2", AmiglEvalPoint2 },
     { "glEvalMesh1", AmiglEvalMesh1 },
     { "glEvalMesh2", AmiglEvalMesh2 },
     { "glFogf", AmiglFogf },
     { "glFogi", AmiglFogi },
     { "glFogfv", AmiglFogfv },
     { "glFogiv", AmiglFogiv },
     { "glFeedbackBuffer", AmiglFeedbackBuffer },
     { "glPassThrough", AmiglPassThrough },
     { "glSelectBuffer", AmiglSelectBuffer },
     { "glInitNames", AmiglInitNames },
     { "glLoadName", AmiglLoadName },
     { "glPushName", AmiglPushName },
     { "glPopName", AmiglPopName },
   #if 1
     { "glBlendEquationEXT", AmiglBlendEquationEXT },
     { "glBlendColorEXT", AmiglBlendColorEXT },
     { "glPolygonOffsetEXT", AmiglPolygonOffsetEXT },
     { "glVertexPointerEXT", AmiglVertexPointerEXT },
     { "glNormalPointerEXT", AmiglNormalPointerEXT },
     { "glColorPointerEXT", AmiglColorPointerEXT },
     { "glIndexPointerEXT", AmiglIndexPointerEXT },
     { "glTexCoordPointerEXT", AmiglTexCoordPointerEXT },
     { "glEdgeFlagPointerEXT", AmiglEdgeFlagPointerEXT },
     { "glGetPointervEXT", AmiglGetPointervEXT },
     { "glArrayElementEXT", AmiglArrayElementEXT },
     { "glDrawArraysEXT", AmiglDrawArraysEXT },
     { "glGenTexturesEXT", AmiglGenTexturesEXT },
     { "glDeleteTexturesEXT", AmiglDeleteTexturesEXT },
     { "glBindTextureEXT", AmiglBindTextureEXT },
     { "glPrioritizeTexturesEXT", AmiglPrioritizeTexturesEXT },
     { "glAreTexturesResidentEXT", AmiglAreTexturesResidentEXT },
     { "glIsTextureEXT", AmiglIsTextureEXT },
     { "glTexImage3DEXT", AmiglTexImage3DEXT },
     { "glTexSubImage3DEXT", AmiglTexSubImage3DEXT },
     { "glCopyTexSubImage3DEXT", AmiglCopyTexSubImage3DEXT },
     { "glColorTableEXT", AmiglColorTableEXT },
     { "glColorSubTableEXT", AmiglColorSubTableEXT },
     { "glGetColorTableEXT", AmiglGetColorTableEXT },
     { "glGetColorTableParameterfvEXT", AmiglGetColorTableParameterfvEXT },
     { "glGetColorTableParameterivEXT", AmiglGetColorTableParameterivEXT },
     { "glMultiTexCoord1dSGIS", AmiglMultiTexCoord1dSGIS },
     { "glMultiTexCoord1dvSGIS", AmiglMultiTexCoord1dvSGIS },
     { "glMultiTexCoord1fSGIS", AmiglMultiTexCoord1fSGIS },
     { "glMultiTexCoord1fvSGIS", AmiglMultiTexCoord1fvSGIS },
     { "glMultiTexCoord1iSGIS", AmiglMultiTexCoord1iSGIS },
     { "glMultiTexCoord1ivSGIS", AmiglMultiTexCoord1ivSGIS },
     { "glMultiTexCoord1sSGIS", AmiglMultiTexCoord1sSGIS },
     { "glMultiTexCoord1svSGIS", AmiglMultiTexCoord1svSGIS },
     { "glMultiTexCoord2dSGIS", AmiglMultiTexCoord2dSGIS },
     { "glMultiTexCoord2dvSGIS", AmiglMultiTexCoord2dvSGIS },
     { "glMultiTexCoord2fSGIS", AmiglMultiTexCoord2fSGIS },
     { "glMultiTexCoord2fvSGIS", AmiglMultiTexCoord2fvSGIS },
     { "glMultiTexCoord2iSGIS", AmiglMultiTexCoord2iSGIS },
     { "glMultiTexCoord2ivSGIS", AmiglMultiTexCoord2ivSGIS },
     { "glMultiTexCoord2sSGIS", AmiglMultiTexCoord2sSGIS },
     { "glMultiTexCoord2svSGIS", AmiglMultiTexCoord2svSGIS },
     { "glMultiTexCoord3dSGIS", AmiglMultiTexCoord3dSGIS },
     { "glMultiTexCoord3dvSGIS", AmiglMultiTexCoord3dvSGIS },
     { "glMultiTexCoord3fSGIS", AmiglMultiTexCoord3fSGIS },
     { "glMultiTexCoord3fvSGIS", AmiglMultiTexCoord3fvSGIS },
     { "glMultiTexCoord3iSGIS", AmiglMultiTexCoord3iSGIS },
     { "glMultiTexCoord3ivSGIS", AmiglMultiTexCoord3ivSGIS },
     { "glMultiTexCoord3sSGIS", AmiglMultiTexCoord3sSGIS },
     { "glMultiTexCoord3svSGIS", AmiglMultiTexCoord3svSGIS },
     { "glMultiTexCoord4dSGIS", AmiglMultiTexCoord4dSGIS },
     { "glMultiTexCoord4dvSGIS", AmiglMultiTexCoord4dvSGIS },
     { "glMultiTexCoord4fSGIS", AmiglMultiTexCoord4fSGIS },
     { "glMultiTexCoord4fvSGIS", AmiglMultiTexCoord4fvSGIS },
     { "glMultiTexCoord4iSGIS", AmiglMultiTexCoord4iSGIS },
     { "glMultiTexCoord4ivSGIS", AmiglMultiTexCoord4ivSGIS },
     { "glMultiTexCoord4sSGIS", AmiglMultiTexCoord4sSGIS },
     { "glMultiTexCoord4svSGIS", AmiglMultiTexCoord4svSGIS },
     { "glMultiTexCoordPointerSGIS", AmiglMultiTexCoordPointerSGIS },
     { "glSelectTextureSGIS", AmiglSelectTextureSGIS },
     { "glSelectTextureCoordSetSGIS", AmiglSelectTextureCoordSetSGIS },
     { "glMultiTexCoord1dEXT", AmiglMultiTexCoord1dEXT },
     { "glMultiTexCoord1dvEXT", AmiglMultiTexCoord1dvEXT },
     { "glMultiTexCoord1fEXT", AmiglMultiTexCoord1fEXT },
     { "glMultiTexCoord1fvEXT", AmiglMultiTexCoord1fvEXT },
     { "glMultiTexCoord1iEXT", AmiglMultiTexCoord1iEXT },
     { "glMultiTexCoord1ivEXT", AmiglMultiTexCoord1ivEXT },
     { "glMultiTexCoord1sEXT", AmiglMultiTexCoord1sEXT },
     { "glMultiTexCoord1svEXT", AmiglMultiTexCoord1svEXT },
     { "glMultiTexCoord2dEXT", AmiglMultiTexCoord2dEXT },
     { "glMultiTexCoord2dvEXT", AmiglMultiTexCoord2dvEXT },
     { "glMultiTexCoord2fEXT", AmiglMultiTexCoord2fEXT },
     { "glMultiTexCoord2fvEXT", AmiglMultiTexCoord2fvEXT },
     { "glMultiTexCoord2iEXT", AmiglMultiTexCoord2iEXT },
     { "glMultiTexCoord2ivEXT", AmiglMultiTexCoord2ivEXT },
     { "glMultiTexCoord2sEXT", AmiglMultiTexCoord2sEXT },
     { "glMultiTexCoord2svEXT", AmiglMultiTexCoord2svEXT },
     { "glMultiTexCoord3dEXT", AmiglMultiTexCoord3dEXT },
     { "glMultiTexCoord3dvEXT", AmiglMultiTexCoord3dvEXT },
     { "glMultiTexCoord3fEXT", AmiglMultiTexCoord3fEXT },
     { "glMultiTexCoord3fvEXT", AmiglMultiTexCoord3fvEXT },
     { "glMultiTexCoord3iEXT", AmiglMultiTexCoord3iEXT },
     { "glMultiTexCoord3ivEXT", AmiglMultiTexCoord3ivEXT },
     { "glMultiTexCoord3sEXT", AmiglMultiTexCoord3sEXT },
     { "glMultiTexCoord3svEXT", AmiglMultiTexCoord3svEXT },
     { "glMultiTexCoord4dEXT", AmiglMultiTexCoord4dEXT },
     { "glMultiTexCoord4dvEXT", AmiglMultiTexCoord4dvEXT },
     { "glMultiTexCoord4fEXT", AmiglMultiTexCoord4fEXT },
     { "glMultiTexCoord4fvEXT", AmiglMultiTexCoord4fvEXT },
     { "glMultiTexCoord4iEXT", AmiglMultiTexCoord4iEXT },
     { "glMultiTexCoord4ivEXT", AmiglMultiTexCoord4ivEXT },
     { "glMultiTexCoord4sEXT", AmiglMultiTexCoord4sEXT },
     { "glMultiTexCoord4svEXT", AmiglMultiTexCoord4svEXT },
     { "glInterleavedTextureCoordSetsEXT", AmiglInterleavedTextureCoordSetsEXT },
     { "glSelectTextureEXT", AmiglSelectTextureEXT },
     { "glSelectTextureCoordSetEXT", AmiglSelectTextureCoordSetEXT },
     { "glSelectTextureTransformEXT", AmiglSelectTextureTransformEXT },
     { "glPointParameterfEXT", AmiglPointParameterfEXT },
     { "glPointParameterfvEXT", AmiglPointParameterfvEXT },
     { "glWindowPos2iMESA", AmiglWindowPos2iMESA },
     { "glWindowPos2sMESA", AmiglWindowPos2sMESA },
     { "glWindowPos2fMESA", AmiglWindowPos2fMESA },
     { "glWindowPos2dMESA", AmiglWindowPos2dMESA },
     { "glWindowPos2ivMESA", AmiglWindowPos2ivMESA },
     { "glWindowPos2svMESA", AmiglWindowPos2svMESA },
     { "glWindowPos2fvMESA", AmiglWindowPos2fvMESA },
     { "glWindowPos2dvMESA", AmiglWindowPos2dvMESA },
     { "glWindowPos3iMESA", AmiglWindowPos3iMESA },
     { "glWindowPos3sMESA", AmiglWindowPos3sMESA },
     { "glWindowPos3fMESA", AmiglWindowPos3fMESA },
     { "glWindowPos3dMESA", AmiglWindowPos3dMESA },
     { "glWindowPos3ivMESA", AmiglWindowPos3ivMESA },
     { "glWindowPos3svMESA", AmiglWindowPos3svMESA },
     { "glWindowPos3fvMESA", AmiglWindowPos3fvMESA },
     { "glWindowPos3dvMESA", AmiglWindowPos3dvMESA },
     { "glWindowPos4iMESA", AmiglWindowPos4iMESA },
     { "glWindowPos4sMESA", AmiglWindowPos4sMESA },
     { "glWindowPos4fMESA", AmiglWindowPos4fMESA },
     { "glWindowPos4dMESA", AmiglWindowPos4dMESA },
     { "glWindowPos4ivMESA", AmiglWindowPos4ivMESA },
     { "glWindowPos4svMESA", AmiglWindowPos4svMESA },
     { "glWindowPos4fvMESA", AmiglWindowPos4fvMESA },
     { "glWindowPos4dvMESA", AmiglWindowPos4dvMESA },
     { "glResizeBuffersMESA", AmiglResizeBuffersMESA },
     { "glDrawRangeElements", AmiglDrawRangeElements },
     { "glTexImage3D", AmiglTexImage3D },
     { "glTexSubImage3D", AmiglTexSubImage3D },
     { "glCopyTexSubImage3D", AmiglCopyTexSubImage3D },
     { "glLockArraysEXT", AmiglLockArraysEXT },
     { "glUnlockArraysEXT", AmiglUnlockArraysEXT },
   #endif

	#if 0
     { "gluLookAt", AmigluLookAt },
     { "gluOrtho2D", AmigluOrtho2D },
     { "gluPerspective", AmigluPerspective },
     { "gluPickMatrix", AmigluPickMatrix },
     { "gluProject", AmigluProject },
     { "gluUnProject", AmigluUnProject },
     { "gluErrorString", AmigluErrorString },
     { "gluScaleImage", AmigluScaleImage },
     { "gluBuild1DMipmaps", AmigluBuild1DMipmaps },
     { "gluBuild2DMipmaps", AmigluBuild2DMipmaps },
     { "gluNewQuadric", AmigluNewQuadric },
     { "gluDeleteQuadric", AmigluDeleteQuadric },
     { "gluQuadricDrawStyle", AmigluQuadricDrawStyle },
     { "gluQuadricOrientation", AmigluQuadricOrientation },
     { "gluQuadricNormals", AmigluQuadricNormals },
     { "gluQuadricTexture", AmigluQuadricTexture },
     { "gluQuadricCallback", AmigluQuadricCallback },
     { "gluCylinder", AmigluCylinder },
     { "gluSphere", AmigluSphere },
     { "gluDisk", AmigluDisk },
     { "gluPartialDisk", AmigluPartialDisk },
     { "gluNewNurbsRenderer", AmigluNewNurbsRenderer },
     { "gluDeleteNurbsRenderer", AmigluDeleteNurbsRenderer },
     { "gluLoadSamplingMatrices", AmigluLoadSamplingMatrices },
     { "gluNurbsProperty", AmigluNurbsProperty },
     { "gluGetNurbsProperty", AmigluGetNurbsProperty },
     { "gluBeginCurve", AmigluBeginCurve },
     { "gluEndCurve", AmigluEndCurve },
     { "gluNurbsCurve", AmigluNurbsCurve },
     { "gluBeginSurface", AmigluBeginSurface },
     { "gluEndSurface", AmigluEndSurface },
     { "gluNurbsSurface", AmigluNurbsSurface },
     { "gluBeginTrim", AmigluBeginTrim },
     { "gluEndTrim", AmigluEndTrim },
     { "gluPwlCurve", AmigluPwlCurve },
     { "gluNurbsCallback", AmigluNurbsCallback },
     { "gluNewTess", AmigluNewTess },
     { "gluTessCallback", AmigluTessCallback },
     { "gluDeleteTess", AmigluDeleteTess },
     { "gluBeginPolygon", AmigluBeginPolygon },
     { "gluEndPolygon", AmigluEndPolygon },
     { "gluNextContour", AmigluNextContour },
     { "gluTessVertex", AmigluTessVertex },
     { "gluGetString", AmigluGetString },
	#endif

      { NULL, NULL }
   };

   CONST struct MyGLFunc *tb = table;

   do
   {
      if (!strcmp(tb->name, proc))
      {
         return tb->func;
      }
      tb++;
   }
   while (tb->name);

   return NULL;
}

#endif /*HAVE_OPENGL*/
