#include "nativeInterface.h"

JNIEXPORT jlong JNICALL Java_com_orcchg_openglsample_NativeInterface_init
  (JNIEnv *, jobject) {
  auto ptr = new NativeInterface();
  jlong descriptor = (jlong)(intptr_t) ptr;
  return descriptor;
}

JNIEXPORT void JNICALL Java_com_orcchg_openglsample_NativeInterface_setSurface
  (JNIEnv *jenv, jobject, jlong descriptor, jobject surface) {
  NativeInterface* ptr = (NativeInterface*) descriptor;
  if (surface == nullptr) {
    ANativeWindow_release(ptr->window);
    ptr->window = nullptr;
  } else {
    ptr->window = ANativeWindow_fromSurface(jenv, surface);
    ptr->render->setSurface(ptr->window);
    ptr->render->draw();
  }
}

JNIEXPORT void JNICALL Java_com_orcchg_openglsample_NativeInterface_destroy
  (JNIEnv *, jobject, jlong descriptor) {
  NativeInterface* ptr = (NativeInterface*) descriptor;
  delete ptr;
  ptr = nullptr;
}

NativeInterface::NativeInterface()
  : render(new Render()) {
}

NativeInterface::~NativeInterface() {
  delete render;
  render = nullptr;
}
