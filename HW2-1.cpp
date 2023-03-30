#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;
class SpatialFilter {
    public:
        Mat smoothing(Mat src) {
            Mat img_blur;
            blur(src, img_blur, Size(3, 3), Point(-1, -1));
            return img_blur;
        }
        Mat median(Mat src) {
            Mat img_median_blur;
            medianBlur(src, img_median_blur, 3);
            return img_median_blur;
        }
};
int main()
{
    Mat img_src = imread("2-1_Image.png");
    Mat img_smoothing, img_median;
    if (!img_src.data)
    {
        cout << "檔案開啟失敗" << endl;
        return 0;
    }
    SpatialFilter SF;
    img_smoothing = SF.smoothing(img_src);
    imshow("Original", img_src);
    imshow("Smoothing", img_smoothing);
    imwrite("Smoothing Filter.png", img_smoothing);

    img_median = SF.median(img_src);
    imshow("Median", img_median);
    imwrite("Median Filter.png", img_median);
    
    waitKey(0);
    return 0;
}

