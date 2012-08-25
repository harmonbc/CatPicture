/**
 * @file CatPictureApp.cpp
 * A simple app that changes the color of the background
 *
 * @author Brandon Harmon
 * @date 2012-08-24
 *
 * @note This file is (c) 2012. It is licensed under the 
 * CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
 * which means you are free to use, share, and remix it as long as you
 * give attribution. Commercial uses are allowed.
 */

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class CatPictureApp : public AppBasic {
  public:
	void setup();
	void update();
	void draw();

  private:
	float red;
	float green;
	float blue;
	bool redFinished;
	bool blueFinished;
	bool greenFinished;
	

};

void CatPictureApp::setup()
{
	red = 0.0f;
	green = 0.0f;
	blue = 0.0f;
	redFinished = false;
	greenFinished = false;
}

void CatPictureApp::update()
{

/// 0.0f is a flag that the color is out of range. After a color has
/// finished its display it will be set to 0 and the next range of RGB
/// will be activated.

	if(!redFinished)
	{
		red = red+ 0.01f;

		if(red > 1.0f)
		{
			
			red = 0.0f;
			redFinished = true;
		}
	}
	else if(!greenFinished)
	{
		green = green + 0.01f;

		if(green > 1.0f)
		{
			green = 0.0f;
			greenFinished= true;
		}
		
	}
	else
	{
		blue = blue + 0.01f;

		if(blue > 1.0f)
		{
			redFinished = false;
			greenFinished = false;
			blue = 0.0f;
		}
	}
}

void CatPictureApp::draw()
{
	gl::clear( Color( red, green, blue ) );
	
}

CINDER_APP_BASIC( CatPictureApp, RendererGl )
