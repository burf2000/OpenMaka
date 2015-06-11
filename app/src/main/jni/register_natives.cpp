#include <jni.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "native_interface.h"

#ifndef NELEM
#define NELEM(x) ((int)(sizeof(x) / sizeof((x)[0])))
#endif

static const char *s_class_path_name = "de/alextape/openmaka/NativeFunctions";

static JNINativeMethod s_methods[] = {
	{"native_start", "()V", (void*) native_start},
	{"native_glResize", "(II)V", (void*) native_glResize},
	{"native_glRender", "()V", (void*) native_glRender},
	{"native_keyEvent", "(II)V", (void*) native_keyEvent},
	{"native_touchEvent", "(FFI)V", (void*) native_touchEvent},
	{"native_displayFunction", "(JJ)I", (int*) native_displayFunction},
	{"native_initialize", "(JLjava/lang/String;)Z", (bool*) native_initialize},
    // {"native_findFeatures", "(JJ)I", (int*) native_findFeatures},
    {"native_setObjectDetection", "(Z)V", (void*) native_setObjectDetection},
    {"native_setTracking", "(Z)V", (void*) native_setTracking},
    {"native_setOpenGL", "(Z)V", (void*) native_setOpenGL}

};

static int register_native_methods(JNIEnv* env,
		const char* class_name,
		JNINativeMethod* methods,
		int num_methods)
{
	jclass clazz;

	clazz = env->FindClass(class_name);
	if (clazz == NULL) {
		fprintf(stderr, "Native registration unable to find class '%s'\n",
				class_name);
		return JNI_FALSE;
	}
	if (env->RegisterNatives(clazz, methods, num_methods) < 0) {
		fprintf(stderr, "RegisterNatives failed for '%s'\n", class_name);
		return JNI_FALSE;
	}

	return JNI_TRUE;
}

static int register_natives(JNIEnv *env)
{
	return register_native_methods(env,
			s_class_path_name,
			s_methods,
			NELEM(s_methods));
}

jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved UNUSED)
{
	JNIEnv* env = NULL;
	jint result = -1;

	if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
		fprintf(stderr, "ERROR: GetEnv failed\n");
		goto bail;
	}
	assert(env != NULL);

	if (register_natives(env) < 0) {
		fprintf(stderr, "ERROR: Exif native registration failed\n");
		goto bail;
	}

	/* success -- return valid version number */
	result = JNI_VERSION_1_4;
bail:
	return result;
}

