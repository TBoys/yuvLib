#include <jni.h>
#include <string>
#include "yuv2rgb.cpp"

extern "C" {
JNIEXPORT jint JNICALL
Java_com_hisign_yuvlib_yuvUtil_YUV420SP2ARGB( JNIEnv* env, jobject obj, jint width, jint height, jbyteArray yuvByteArray, jbyteArray rgbByteArry)
{

    int nRet = -1;

#if 0

    const char  *p_InPath = env->GetStringUTFChars(yuvInPath, 0);
    const char  *p_OutPath = env->GetStringUTFChars(rgbOutPath, 0);
    if (p_InPath!=NULL && p_OutPath!=NULL)
	{
        nRet = SaveYUVtoBmp(p_InPath, p_OutPath);
    }

	env->ReleaseStringUTFChars(yuvInPath, p_InPath);
    env->ReleaseStringUTFChars(rgbOutPath, p_OutPath);

	return nRet;
#endif

    jboolean b;
    jbyte* srcPtr = env->GetByteArrayElements(yuvByteArray, &b);
    jbyte* dstPtr = env->GetByteArrayElements(rgbByteArry, &b);

    jsize alen = env->GetArrayLength(yuvByteArray);

    if (alen >= width*height*2/3)
    {
        unsigned char *dstByte = (unsigned char *)dstPtr;
        nRet = YUV420SPtoARGB(&dstByte, width, height, (unsigned char *)srcPtr);
    }

    env->ReleaseByteArrayElements(yuvByteArray, srcPtr, JNI_ABORT);  // free and not copy to java
    env->ReleaseByteArrayElements(rgbByteArry, dstPtr, 0);		// copy to java and free

    return nRet;
}

JNIEXPORT jint JNICALL
Java_com_hisign_yuvlib_yuvUtil_YUV420SP2RGBA( JNIEnv* env, jobject obj, jint width, jint height, jbyteArray yuvByteArray, jbyteArray rgbByteArry)
{

    int nRet = -1;

#if 0

    const char  *p_InPath = env->GetStringUTFChars(yuvInPath, 0);
    const char  *p_OutPath = env->GetStringUTFChars(rgbOutPath, 0);
    if (p_InPath!=NULL && p_OutPath!=NULL)
	{
        nRet = SaveYUVtoBmp(p_InPath, p_OutPath);
    }

	env->ReleaseStringUTFChars(yuvInPath, p_InPath);
    env->ReleaseStringUTFChars(rgbOutPath, p_OutPath);

	return nRet;
#endif

    jboolean b;
    jbyte* srcPtr = env->GetByteArrayElements(yuvByteArray, &b);
    jbyte* dstPtr = env->GetByteArrayElements(rgbByteArry, &b);

    jsize alen = env->GetArrayLength(yuvByteArray);

    if (alen >= width*height*2/3)
    {
        unsigned char *dstByte = (unsigned char *)dstPtr;
        nRet = YUV420SPtoRGBA(&dstByte, width, height, (unsigned char *)srcPtr);
    }

    env->ReleaseByteArrayElements(yuvByteArray, srcPtr, JNI_ABORT);  // free and not copy to java
    env->ReleaseByteArrayElements(rgbByteArry, dstPtr, 0);		// copy to java and free

    return nRet;
}


extern "C" JNIEXPORT jint JNICALL
Java_com_hisign_yuvlib_yuvUtil_YUV420SP2RGB( JNIEnv* env, jobject obj, jint width, jint height, jbyteArray yuvByteArray, jbyteArray rgbByteArry)
{

    int nRet = -1;

#if 0

    const char  *p_InPath = env->GetStringUTFChars(yuvInPath, 0);
    const char  *p_OutPath = env->GetStringUTFChars(rgbOutPath, 0);
    if (p_InPath!=NULL && p_OutPath!=NULL)
	{
        nRet = SaveYUVtoBmp(p_InPath, p_OutPath);
    }

	env->ReleaseStringUTFChars(yuvInPath, p_InPath);
    env->ReleaseStringUTFChars(rgbOutPath, p_OutPath);

	return nRet;
#endif

    jboolean b;
    jbyte* srcPtr = env->GetByteArrayElements(yuvByteArray, &b);
    jbyte* dstPtr = env->GetByteArrayElements(rgbByteArry, &b);

    jsize alen = env->GetArrayLength(yuvByteArray);

    if (alen >= width*height*2/3)
    {
        unsigned char *dstByte = (unsigned char *)dstPtr;
        nRet = YUV420SPtoRGB(&dstByte, width, height, (unsigned char *)srcPtr);
    }

    env->ReleaseByteArrayElements(yuvByteArray, srcPtr, JNI_ABORT);  // free and not copy to java
    env->ReleaseByteArrayElements(rgbByteArry, dstPtr, 0);		// copy to java and free

    return nRet;
}

JNIEXPORT jint JNICALL
Java_com_hisign_yuvlib_yuvUtil_YUV420SP2BGR( JNIEnv* env, jobject obj, jint width, jint height, jbyteArray yuvByteArray, jbyteArray rgbByteArry)
{

    int nRet = -1;

#if 0

    const char  *p_InPath = env->GetStringUTFChars(yuvInPath, 0);
    const char  *p_OutPath = env->GetStringUTFChars(rgbOutPath, 0);
    if (p_InPath!=NULL && p_OutPath!=NULL)
	{
        nRet = SaveYUVtoBmp(p_InPath, p_OutPath);
    }

	env->ReleaseStringUTFChars(yuvInPath, p_InPath);
    env->ReleaseStringUTFChars(rgbOutPath, p_OutPath);

	return nRet;
#endif

    jboolean b;
    jbyte* srcPtr = env->GetByteArrayElements(yuvByteArray, &b);
    jbyte* dstPtr = env->GetByteArrayElements(rgbByteArry, &b);

    jsize alen = env->GetArrayLength(yuvByteArray);

    if (alen >= width*height*2/3)
    {
        unsigned char *dstByte = (unsigned char *)dstPtr;
        nRet = YUV420SPtoBGR(&dstByte, width, height, (unsigned char *)srcPtr);
    }

    env->ReleaseByteArrayElements(yuvByteArray, srcPtr, JNI_ABORT);  // free and not copy to java
    env->ReleaseByteArrayElements(rgbByteArry, dstPtr, 0);		// copy to java and free

    return nRet;
}

JNIEXPORT jint JNICALL
Java_com_hisign_yuvlib_yuvUtil_YUV420SP2Flip( JNIEnv* env, jobject obj, jint width, jint height, jbyteArray yuvSrcByteArray)
{

    int nRet = -1;
    jboolean b;
    jbyte* srcPtr = env->GetByteArrayElements(yuvSrcByteArray, &b);
    jsize alen = env->GetArrayLength(yuvSrcByteArray);

    if (alen >= width*height*2/3)
    {

        nRet = YUV420SPFlip((unsigned char *)srcPtr, width, height);
    }

    env->ReleaseByteArrayElements(yuvSrcByteArray, srcPtr, 0);		// copy to java and free

    return nRet;
}

JNIEXPORT jint JNICALL
Java_com_hisign_yuvlib_yuvUtil_YUV420SP2Mirror( JNIEnv* env, jobject obj, jint width, jint height, jbyteArray yuvSrcByteArray, jint angle, jint isMirror)
{
    int nRet = -1;
    jboolean b;
    jbyte* srcPtr = env->GetByteArrayElements(yuvSrcByteArray, &b);
    jsize alen = env->GetArrayLength(yuvSrcByteArray);

    if (alen >= width*height*2/3)
    {
        nRet = YUV420SPMirror((unsigned char *)srcPtr, width, height, angle, isMirror);
    }
    env->ReleaseByteArrayElements(yuvSrcByteArray, srcPtr, 0);	// copy to java and free

    return nRet;

}
JNIEXPORT jint JNICALL
Java_com_hisign_yuvlib_yuvUtil_NV21ToNV12( JNIEnv* env, jobject obj, jint width, jint height, jbyteArray jNv21Data, jbyteArray jNv12Data)
{
    jbyte* jNv21 = env->GetByteArrayElements(jNv21Data, nullptr);
    jbyte* jNv12 = env->GetByteArrayElements(jNv12Data, nullptr);

    unsigned char* pNv21 = (unsigned char*)jNv21;
    unsigned char* pNv12 = (unsigned char*)jNv12;

    int nRet = Nv21ToNv12(pNv21,pNv12,(int)width, (int)height);
    env->ReleaseByteArrayElements(jNv21Data, jNv21, 0);
    env->ReleaseByteArrayElements(jNv12Data, jNv12, 0);

    return nRet;

}

JNIEXPORT jint JNICALL
Java_com_hisign_yuvlib_yuvUtil_NV12ToNV21( JNIEnv* env, jobject obj, jint width, jint height, jbyteArray jNv12Data, jbyteArray jNv21Data)
{
    jbyte* jNv21 = env->GetByteArrayElements(jNv21Data, nullptr);
    jbyte* jNv12 = env->GetByteArrayElements(jNv12Data, nullptr);

    unsigned char* pNv21 = (unsigned char*)jNv21;
    unsigned char* pNv12 = (unsigned char*)jNv12;

    int nRet = Nv12ToNv21(pNv12,pNv21,(int)width, (int)height);
    env->ReleaseByteArrayElements(jNv21Data, jNv21, 0);
    env->ReleaseByteArrayElements(jNv12Data, jNv12, 0);

    return nRet;

}

JNIEXPORT jint JNICALL
Java_com_hisign_yuvlib_yuvUtil_NV21ToYV12( JNIEnv* env, jobject obj, jint width, jint height, jbyteArray jNv21Data, jbyteArray jYv12Data)
{
    jbyte* jNv21 = env->GetByteArrayElements(jNv21Data, nullptr);
    jbyte* jYv12 = env->GetByteArrayElements(jYv12Data, nullptr);

    unsigned char* pNv21 = (unsigned char*)jNv21;
    unsigned char* pYv12 = (unsigned char*)jYv12;

    int nRet = Nv21ToYv12(pNv21,pYv12,(int)width, (int)height);
    env->ReleaseByteArrayElements(jNv21Data, jNv21, 0);
    env->ReleaseByteArrayElements(jYv12Data, jYv12, 0);

    return nRet;

}

JNIEXPORT jint JNICALL
Java_com_hisign_yuvlib_yuvUtil_YV12ToNV21( JNIEnv* env, jobject obj, jint width, jint height, jbyteArray jYv12Data, jbyteArray jNv21Data)
{
    jbyte* jNv21 = env->GetByteArrayElements(jNv21Data, nullptr);
    jbyte* jYv12 = env->GetByteArrayElements(jYv12Data, nullptr);

    unsigned char* pNv21 = (unsigned char*)jNv21;
    unsigned char* pYv12 = (unsigned char*)jYv12;

    int nRet = Yv12ToNv21(pYv12,pNv21,(int)width, (int)height);
    env->ReleaseByteArrayElements(jNv21Data, jNv21, 0);
    env->ReleaseByteArrayElements(jYv12Data, jYv12, 0);

    return nRet;

}

JNIEXPORT jint JNICALL
Java_com_hisign_yuvlib_yuvUtil_NV21ToI420( JNIEnv* env, jobject obj, jint width, jint height, jbyteArray jNv21Data, jbyteArray jI420Data)
{
    jbyte* jNv21 = env->GetByteArrayElements(jNv21Data, nullptr);
    jbyte* jI420 = env->GetByteArrayElements(jI420Data, nullptr);

    unsigned char* pNv21 = (unsigned char*)jNv21;
    unsigned char* pI420 = (unsigned char*)jI420;

    int nRet = Nv21ToI420(pNv21,pI420,(int)width, (int)height);
    env->ReleaseByteArrayElements(jNv21Data, jNv21, 0);
    env->ReleaseByteArrayElements(jI420Data, jI420, 0);

    return nRet;

}

JNIEXPORT jint JNICALL
Java_com_hisign_yuvlib_yuvUtil_I420ToNV21( JNIEnv* env, jobject obj, jint width, jint height, jbyteArray jI420Data, jbyteArray jNv21Data)
{
    jbyte* jNv21 = env->GetByteArrayElements(jNv21Data, nullptr);
    jbyte* jI420 = env->GetByteArrayElements(jI420Data, nullptr);

    unsigned char* pNv21 = (unsigned char*)jNv21;
    unsigned char* pI420 = (unsigned char*)jI420;

    int nRet = I420ToNv21(pI420,pNv21,(int)width, (int)height);
    env->ReleaseByteArrayElements(jNv21Data, jNv21, 0);
    env->ReleaseByteArrayElements(jI420Data, jI420, 0);

    return nRet;

}
JNIEXPORT jint JNICALL
Java_com_hisign_yuvlib_yuvUtil_YV12ToI420( JNIEnv* env, jobject obj, jint width, jint height, jbyteArray jYv12Data, jbyteArray jI420Data)
{
    jbyte* jYv12 = env->GetByteArrayElements(jYv12Data, nullptr);
    jbyte* jI420 = env->GetByteArrayElements(jI420Data, nullptr);

    unsigned char* pYv12 = (unsigned char*)jYv12;
    unsigned char* pI420 = (unsigned char*)jI420;

    int nRet = Yv12ToI420(pI420,pYv12,(int)width, (int)height);
    env->ReleaseByteArrayElements(jYv12Data, jYv12, 0);
    env->ReleaseByteArrayElements(jI420Data, jI420, 0);

    return nRet;

}
JNIEXPORT jint JNICALL
Java_com_hisign_yuvlib_yuvUtil_I420ToYV12( JNIEnv* env, jobject obj, jint width, jint height, jbyteArray jI420Data, jbyteArray jYv12Data)
{
    jbyte* jYv12 = env->GetByteArrayElements(jYv12Data, nullptr);
    jbyte* jI420 = env->GetByteArrayElements(jI420Data, nullptr);

    unsigned char* pYv12 = (unsigned char*)jYv12;
    unsigned char* pI420 = (unsigned char*)jI420;

    int nRet = I420ToYv12(pI420,pYv12,(int)width, (int)height);
    env->ReleaseByteArrayElements(jYv12Data, jYv12, 0);
    env->ReleaseByteArrayElements(jI420Data, jI420, 0);

    return nRet;

}
}
