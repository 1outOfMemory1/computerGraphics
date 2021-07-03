#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>

std::vector<cv::Point2f> control_points;





cv::Point2f lerp_v2f(const cv::Point2f& a, const cv::Point2f& b, float t)
{
    return a + (b - a) * t;
}


cv::Point2f recursive_bezier(const std::vector<cv::Point2f> &control_points, float t)
{
    if (control_points.size() == 1)
    {
        return control_points[0];
    }


    std::vector<cv::Point2f> lerp_points;
    for (size_t i = 1;i<control_points.size();i++)
    {
        lerp_points.push_back(lerp_v2f(control_points[i - 1], control_points[i], t));
    }
    return recursive_bezier(lerp_points,t);
}

void bezier(const std::vector<cv::Point2f> &control_points, cv::Mat &window)
{
    // TODO: Iterate through all t = 0 to t = 1 with small steps, and call de Casteljau's
    // recursive Bezier algorithm.
    for (double t = 0.0;t<=1.0;t+=0.001)
    {
        auto point = recursive_bezier(control_points, t);
        window.at<cv::Vec3b>(point.y, point.x)[1] = 255;
    }

}


cv::Mat window;




void mouse_handler(int event, int x, int y, int flags, void *userdata)
{
    if (event == cv::EVENT_LBUTTONDOWN )
    {
        std::cout << "Left button of the mouse is clicked - position (" << x << ", "
                  << y << ")" << '\n';
        control_points.emplace_back(x, y);
        for (auto &point : control_points)
        {
            cv::circle(window, point, 1, {255, 255, 255}, 3);
        }
        cv::imshow("Bezier Curve", window);
    }


    if (event == cv::EVENT_RBUTTONDOWN )
    {
        std::cout << "asdfasfd"<<std::endl;
        bezier(control_points, window);
        cv::imshow("Bezier Curve", window);
    }
}

int main()
{
    window = cv::Mat(700, 700, CV_8UC3, cv::Scalar(0));
    cv::cvtColor(window, window, cv::COLOR_BGR2RGB);
    cv::namedWindow("Bezier Curve", cv::WINDOW_AUTOSIZE);
    cv::setMouseCallback("Bezier Curve", mouse_handler, nullptr);

    int key = -1;
    while (key != 27)
    {
        key = cv::waitKey(0);
    }

    return 0;
}


