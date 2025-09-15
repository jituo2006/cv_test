#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "please input: " << argv[0] << " path/to/image.png" << std::endl;
        return -1;
    }

    std::string imagePath = argv[1];

    // 1. 读取图片
    cv::Mat img = cv::imread(imagePath);
    if (img.empty()) {
        std::cerr << "Unable to load image: " << imagePath << std::endl;
        return -1;
    }

    // 2. 灰度化
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    // 3. Canny 边缘检测
    cv::Mat edges;
    cv::Canny(gray, edges, 100, 200);

    // 4. 查找轮廓
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(edges, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    if (contours.empty()) {
        std::cout << "No contours detected!" << std::endl;
        cv::imshow("Edges", edges);
        cv::imshow("Original", img);
        cv::waitKey(0);
        return 0;
    }

    double bestScore = 0.0;
    std::vector<cv::Point> bestContour;

    for (const auto& contour : contours) {
        double area = cv::contourArea(contour);
        double perimeter = cv::arcLength(contour, true);
        if (perimeter == 0) continue;
        double circularity = 4 * CV_PI * area / (perimeter * perimeter);

        if (area < 50 || area > img.rows*img.cols*0.9) continue;
        if (circularity > bestScore && circularity > 0.6) {
            bestScore = circularity;
            bestContour = contour;
        }
    }

    // 5. 标记最圆轮廓
    if (!bestContour.empty()) {
        cv::Point2f center;
        float radius;
        cv::minEnclosingCircle(bestContour, center, radius);
        cv::Rect bbox(cvRound(center.x - radius), cvRound(center.y - radius),
                      cvRound(2*radius), cvRound(2*radius));
        bbox &= cv::Rect(0,0,img.cols,img.rows); 
        // 裁剪到图像边界
        cv::rectangle(img, bbox, cv::Scalar(0, 0, 255), 2, cv::LINE_AA);

        //std::cout << "Detected radius: " << radius << " , circularity: " << bestScore << std::endl;
    } else {
        std::cout << "No circular contour detected!" << std::endl;
    }

    // 显示结果
    cv::imshow("Edges", edges);
    cv::imshow("Detected Circle", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}