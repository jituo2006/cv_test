#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    // 设置参数检查以提升健壮性
    if (argc != 2) {
        std::cerr << "PLease input: " << argv[0] << " <image_path>" << std::endl;
        return -1;
    }

    std::string imagePath = argv[1];

    // 1. 读取图片
    cv::Mat img = cv::imread(imagePath);
    if (img.empty()) {
        std::cerr << "Image not found: " << imagePath << std::endl;
        return -1;
    }

    // 2. BGR -> HSV
    cv::Mat hsv;
    cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);

    // 3. 设置红色的HSV阈值范围
    cv::Mat mask1, mask2, mask;
    cv::inRange(hsv, cv::Scalar(0, 120, 70), cv::Scalar(10, 255, 255), mask1);
    cv::inRange(hsv, cv::Scalar(170, 120, 70), cv::Scalar(180, 255, 255), mask2);

    mask = mask1 | mask2; 
    // 合并两个范围

    // 4. 显示结果
    cv::imshow("Original Image", img);
    cv::imshow("Red Mask", mask);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}