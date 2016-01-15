#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osg/Material>
#include <osg/Texture2D>

#include <osgViewer/Viewer>
#include <iostream>
#include <osgDB/ReadFile>
#include <osg/Math>
#include <osg/Matrixd>
#include <osg/MatrixTransform>
#include <osg/Vec3d>
#include <iostream>
#include <osg/PositionAttitudeTransform>

class KeyboardEventHandler : public osgGA::GUIEventHandler
{
public:

    KeyboardEventHandler()
    {}


	virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter&)
	{
		switch(ea.getEventType())
		{
			case(osgGA::GUIEventAdapter::KEYDOWN):
			{
				switch (ea.getKey()) 
				{
					case 'q':
					
						return true;
					case 'a':
					
						return true;
					case 'w':
					 
						return true;
					case 's':
					 
						return true;
					case 'e':
					
						return true;
					case 'd':
					 
						return true;
					case 'r':
											return true;
					case 'f':
					
						return true;
					case 't':
					 
						return true;
					
				}
			}
			default:
				break;
				
		}
		//return false to allow mouse manipulation
		return false;
	}

private:
	int posicion;
};