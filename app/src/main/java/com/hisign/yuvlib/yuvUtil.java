package com.hisign.yuvlib;

public class yuvUtil {
    static {
        System.loadLibrary("golangYuv");
    }

    /**
     * YUV420SP to RGBA
     * @param width
     * @param height
     * @param src
     * @param dest
     * @return
     */
    public synchronized native static int YUV420SP2RGBA(int width, int height, byte src[], byte dest[]);

    /**
     * YUV420SP to ARGB
     * @param width
     * @param height
     * @param src
     * @param dest
     * @return
     */
    public synchronized native static int YUV420SP2ARGB(int width, int height, byte src[], byte dest[]);

    /**
     * YUV420SP to RGB
     * @param width
     * @param height
     * @param src
     * @param dest
     * @return
     */
    public synchronized native static int YUV420SP2RGB(int width, int height, byte src[], byte dest[]);

    /**
     * YUV420SP to BGR (Android 默认）
     * @param width
     * @param height
     * @param src
     * @param dest
     * @return
     */
    public synchronized native static int YUV420SP2BGR(int width, int height, byte src[], byte dest[]);

    /**
     * YUV420SP 旋转和镜像
     * @param width
     * @param height
     * @param src
     * @param angle
     * @param isMirror
     * @return
     */
    public synchronized native static int YUV420SP2Mirror(int width, int height, byte src[], int angle, int isMirror);

    /**
     * YUV420SP 垂直翻转
     * @param width
     * @param height
     * @param src
     * @return
     */
    public synchronized native static int YUV420SP2Flip(int width, int height, byte src[]);

    /**
     * YUV420SP NV21 -> NV12
     * @param width
     * @param height
     * @param nv21
     * @param nv12
     * @return
     */
    public synchronized native static int NV21ToNV12(int width, int height, byte nv21[], byte nv12[]);

    /**
     * YUV420SP NV12 -> NV21
     * @param width
     * @param height
     * @param nv21
     * @param nv12
     * @return
     */
    public synchronized native static int NV12ToNV21(int width, int height, byte nv12[], byte nv21[]);

    /**
     * YUV420SP -> YUV420P
     * @param width
     * @param height
     * @param nv21
     * @param yv12
     * @return
     */
    public synchronized native static int NV21ToYV12(int width, int height, byte nv21[], byte yv12[]);

    /**
     * YUV420P -> YUV420SP
     * @param width
     * @param height
     * @param nv21
     * @param yv12
     * @return
     */
    public synchronized native static int YV12ToNV21(int width, int height, byte yv12[], byte nv21[]);

    /**
     * YUV420SP -> I420
     * @param width
     * @param height
     * @param nv21
     * @param i420
     * @return
     */
    public synchronized native static int NV21ToI420(int width, int height, byte nv21[], byte i420[]);

    /**
     * I420 -> YUV420SP
     * @param width
     * @param height
     * @param nv21
     * @param i420
     * @return
     */
    public synchronized native static int I420ToNV21(int width, int height, byte i420[], byte nv21[]);


}
