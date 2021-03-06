#include <jni.h>
#include <android/log.h>
#include <string.h>
#include <math.h>

#define TAG "CheckJni"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)


// 引数の数値を加算して返す
jfloat Java_com_example_jni_CheckJniActivity_addFieldValues(JNIEnv* env, jobject thiz){

  // クラスを取得する
  // Cで書くと　jclass klass = (*env)->GetObjectClass(env, thiz);
  jclass klass = env->GetObjectClass(thiz);

  // フィールド変数(mValueFoo)の値を取得する
  jfieldID jfield1 = env->GetFieldID(klass, "mValueFoo", "F");
  if (jfield1 == NULL)
    return INFINITY;
  jfloat val1 = env->GetFloatField(thiz, jfield1);

  // スタティックフィールド変数(mValueBar)の値を取得する
  jfieldID jfield2 = env->GetStaticFieldID(klass, "mValueBar", "F");
  if (jfield2 == NULL)
    return INFINITY;
  jfloat val2 = env->GetStaticFloatField(klass, jfield2);

  // 加算する
  float answer = val1 + val2;

  // フィールド変数(mValueFoo)に値を格納する
  env->SetFloatField(thiz, jfield1,answer);

  return val1+val2;
}

