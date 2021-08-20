// This may look like C code, but it is really -*- C++ -*-
//
// Copyright Bob Friesenhahn, 1999, 2003
//
// Demonstration of unary function-object based operations
//
// Reads the multi-frame file "smile_anim.miff" and writes a
// flipped and morphed version to "flip_out.miff".
//
//
// Redisigned for test Image Magick
// Added libs (without them it didn't work
// Added ifstream to test binary images (not completed)
// 
// This code might compile without errors only in release mode. 
// If you want to debug it correctly, you must compile all libs by yourself
// Webpage for answer:
// legacy.imagemagick.org/discourse-server/viewtopic.php?t=13970
//
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "CORE_RL_Magick++_.lib")
#pragma comment(lib, "CORE_RL_MagickCore_.lib")
#pragma comment(lib, "CORE_RL_MagickWand_.lib")

#include <Magick++.h>
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include <ios>
#include <fstream>

using namespace std;

using namespace Magick;

int main(int /*argc*/, char** argv)
{

    // Initialize ImageMagick install location for Windows
    //InitializeMagick(*argv);


    try {

        string srcdir("");
        if (getenv("SRCDIR") != 0)
            srcdir = getenv("SRCDIR");

        ifstream ifs(L"d:\\about2.jpg", std::ios::binary);

        Image image;
        image.read("D:/smile.jpg");
        image.autoOrient();
        image.write("D:/smile.jpg");

/*        // Read images into STL list
        list<Image> imageList;
        string ImageName = "about2.jpg";
        readImages(&imageList, srcdir + ImageName);

        cout << "Total scenes: " << imageList.size() << endl;

        // Flip images
        for_each(imageList.begin(), imageList.end(), flipImage());

        // Create a morphed version, adding three frames between each
        // existing frame.
        list<Image> morphed;
        morphImages(&morphed, imageList.begin(), imageList.end(), imageList.size());

        // Write out images
        cout << "Writing image \"" << ImageName << "\" ..." << endl;
        writeImages(morphed.begin(), morphed.end(), "flipped_" + ImageName + " ");
        */
    }
    catch (exception& error_)
    {
        cout << "Caught exception: " << error_.what() << endl;
        return 1;
    }

    return 0;
}
