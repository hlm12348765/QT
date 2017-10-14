//
//  Landmark.hpp
//  AuthenFVSDK_Landmark
//
//  Created by fty on 1/12/16.
//  Copyright @2016 fty. All rights reserved.
//

#ifndef Landmark_hpp
#define Landmark_hpp

/**
 * @author ZhaoChenxu
 * @Date 2016-2-25关键点结构体1:18:57
 * @Description 关键点结构体, 未使用* @File fras.h
 */
typedef struct
{
    float   left;
    float   top;
    float   right;
    float   bottom;
    float   score;
    float   roll;
    float   yaw;
    float   pitch;
    float   landmarks[25*2];
} FaceLandMarks;

/**
 * @author ZhaoChenxu
 * @Date 2016-2-25 1:19:09
 * @Description 检测结果结构体
 * @File fras.h
 */
typedef struct
{
    float   left;
    float   top;
    float   right;
    float   bottom;
    float   score;
} DetectionResult;

/**
 * @author ZhaoChenxu
 * @Date 2016-2-25 1:19:09
 * @Description 人脸特征结构, 未使用
 * @File fras.h
 */
#define FEATURE_SIZE 2008
typedef unsigned char Feature[FEATURE_SIZE];

enum {
    FRAS_SUCCESS = 1,
    FRAS_FAILED = 0,
};

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @Description 引擎初始化
     * @param detectorModelPath 检测模型的路径，即npd2所在路径
     * @param lmModelPath 关键点模型路径，即lm所在路径, 未使用
     * @param CorePath 抽特征模型目录, 未使用
     * @return 1 表示成功
     */
    int _fras_initialize(const char* DetectorModelPath, const char* LandmarkModelPath, const char* coreModelPath);

    /**
     * @Description 检测人脸函数
     * @param image 图像像素区（灰度）
     * @param width 图像宽度
     * @param height 图像高度
     * @param maxFace 允许最大人脸个数
     * @return 检测到的人脸个数
     */
    int _fras_detect(unsigned char* image, int width, int height, DetectionResult* detectionResult, int maxFace);

    /**
     * @Description 抽取人脸关键点函数, 未使用
     * @param image 图像像素区（灰度）
     * @param width 图像宽度
     * @param height 图像高度
     * @param landmarks 关键点结果 （传出参数）
     * @param detectionResult 检测结构体结果 （即fras_detect得到的结果）
     * @return 人脸个数
     */
    int _fras_landmarks(unsigned char* image, int width, int height, FaceLandMarks* landmarks, DetectionResult* detectionResult);

    /**
     * @Description 抽取人像特征的函数, 未使用
     * @param image 图像像素区（彩色）
     * @param width 图像宽度
     * @param height 图像高度
     * @param landmarks 关键点结果（传入参数）
     * @param feature 人脸特征（传出参数)
     * @return 1表示成功
     */
    int _fras_extractFeatureFromLandMarks(unsigned char* image, int width, int height, FaceLandMarks* landmarks, Feature fea);

    /**
     * @Description 相似度比对函数, 未使用
     * @param fea1 特征1
     * @param fea2 特征2
     * @return 相似度分数
     */
    float _match(Feature fea1,Feature fea2);

    /**
     * @Description 释放引擎     */
    void _fras_destroy();

#ifdef __cplusplus
}
#endif


#endif /* Landmark_hpp */
