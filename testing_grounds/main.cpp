#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/aruco.hpp>

int main() {
    std::cout << "Hello, World!" << std::endl;

    cv::VideoCapture cap;
    cap.open(1);

    if(!cap.isOpened()){
        std::cout << "Webcam not opened!" << std::endl;
        return 1;
    }

//    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
//    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 720);

    cv::Mat frame, frame2;

    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);

//    for(int i = 0; i < 50; i++){
//        cv::aruco::drawMarker(dictionary, i, 220, frame, 1);
//        cv::imshow("aruco", frame);
//        cv::imwrite("/home/emiel/Desktop/markers/" + std::to_string(i) + ".png", frame);
//        cv::waitKey(100);
//    }


    for(;;){
        cap.read(frame);
//        cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);

        std::vector<int> ids;
        std::vector<std::vector<cv::Point2f> > corners;
        cv::aruco::detectMarkers(frame, dictionary, corners, ids);

        if (ids.size() > 0)
            cv::aruco::drawDetectedMarkers(frame, corners, ids);

        // Find marker with id 0
//        std::vector it0 = std::distance(ids.begin(), std::find(ids.begin(), ids.end(), 0));
//        int it1 = std::distance(ids.begin(), std::find(ids.begin(), ids.end(), 1));
//        int it6 = std::distance(ids.begin(), std::find(ids.begin(), ids.end(), 6));
//        int it7 = std::distance(ids.begin(), std::find(ids.begin(), ids.end(), 7));

//        std::cout << i0 << " " << i1 << " " << i6 << " " << i7 << std::endl;

        cv::imshow("Frame", frame);
        char key = (char) cv::waitKey(100);
        if (key == 27)
            break;
    }

    return 0;
}