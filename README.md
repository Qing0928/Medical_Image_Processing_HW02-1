# Medical_Image_Processing_HW02-1

## Spatial Filter

```
SpatialFilter SF;
img_smoothing = SF.smoothing(img_src);
imshow("Original", img_src);
imshow("Smoothing", img_smoothing);
imwrite("Smoothing Filter.png", img_smoothing);
```

## Median Filter 

```
img_median = SF.median(img_src);
imshow("Median", img_median);
imwrite("Median Filter.png", img_median);
```

class
```
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
```
