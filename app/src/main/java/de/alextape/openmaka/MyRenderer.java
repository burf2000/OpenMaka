package de.alextape.openmaka;

import android.opengl.GLSurfaceView;

import javax.microedition.khronos.opengles.GL10;

/**
 * Created by thinker on 11.05.15.
 */
class MyRenderer implements GLSurfaceView.Renderer {

    @Override
    public void onSurfaceCreated(GL10 gl, javax.microedition.khronos.egl.EGLConfig arg1) {
        MainActivity.native_start();
    }

    public void onSurfaceChanged(GL10 gl, int w, int h) {
        MainActivity.native_gl_resize(w, h);
    }

    public void onDrawFrame(GL10 gl) {
        MainActivity.native_gl_render();
    }

}
