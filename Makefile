CC=gcc

CXX=g++

all:
	$(CXX) show_img.cpp -o show_img `pkg-config opencv --libs` `pkg-config opencv --cflags`
	$(CXX) camera_capture.cpp -o camera_capture `pkg-config opencv --libs` `pkg-config opencv --cflags`
	$(CXX) object_detection.cpp -o object_detection `pkg-config opencv --libs` `pkg-config opencv --cflags`
	$(CXX) camshiftdemo.cpp -o camshiftdemo `pkg-config opencv --libs` `pkg-config opencv --cflags`
	$(CXX) trackbar.cpp -o trackbar `pkg-config opencv --libs` `pkg-config opencv --cflags`
clean:
	rm -rf camera_capture	
	rm -rf show_img
