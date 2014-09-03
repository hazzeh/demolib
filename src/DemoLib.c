// -*- mode:c; indent-tabs-mode:nil; -*-

// JNI interface
#include "demolib_DemoLib.h"

// Native C interface
#include "demolib.h"

// C
#include <string.h>
#include <stdlib.h>

JNIEXPORT jlong JNICALL
Java_demolib_DemoLib_getToken(__attribute__((unused)) JNIEnv* env,
                      __attribute__((unused)) jobject obj,
                      jlong seed) {
  return getToken(seed);
}

JNIEXPORT jstring JNICALL
Java_demolib_DemoLib_getMessage(JNIEnv* env,
                        __attribute__((unused)) jobject obj,
                        jlong token) {
  char const* str = getMessage(token);
  return (*env)->NewStringUTF(env, str);
}

JNIEXPORT jstring JNICALL
Java_demolib_DemoLib_getMessageQuoted(JNIEnv* env,
                              __attribute__((unused)) jobject obj,
                              jlong token) {
  char const* str = getMessageQuoted(token);
  return (*env)->NewStringUTF(env, str);
}

JNIEXPORT jstring JNICALL
Java_demolib_DemoLib_getVersion(JNIEnv* env,
                              __attribute__((unused)) jobject obj) {
  char const* str = getVersion();
  return (*env)->NewStringUTF(env, str);
}
