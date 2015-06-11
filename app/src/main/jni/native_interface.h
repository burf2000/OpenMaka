#ifndef glbuffer_h_seen
#define glbuffer_h_seen

#include <jni.h>

#define UNUSED  __attribute__((unused))
void native_start(JNIEnv *env, jclass clazz);
void native_glResize(JNIEnv *env, jclass clazz, jint w, jint h);
void native_glRender(JNIEnv *env, jclass clazz);
void native_keyEvent(JNIEnv *env,jclass clazz,jint key,jint status);
void native_touchEvent(JNIEnv *env,jclass clazz,jfloat x,jfloat y,jint status);
//int native_findFeatures(JNIEnv *env,jclass clazz,jlong addrGray, jlong addrRgba);
bool native_initialize(JNIEnv *env,jclass clazz,jlong addrFrame, jstring configPath);
int native_displayFunction(JNIEnv *env,jclass clazz,jlong mRgbaAddr, jlong mGrayAddr);
void native_setObjectDetection(JNIEnv *env,jclass clazz,jboolean isActive);
void native_setTracking(JNIEnv *env,jclass clazz,jboolean isActive);
void native_setOpenGL(JNIEnv *env,jclass clazz,jboolean isActive);
#endif
