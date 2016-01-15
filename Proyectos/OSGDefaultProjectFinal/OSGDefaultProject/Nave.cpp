#include <osg/Node>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Texture2D>
#include <osgDB/ReadFile> 
#include <osgViewer/Viewer>
#include <osg/PositionAttitudeTransform>
#include <osgGA/TrackballManipulator>

class nave {
private:
	
	osg::Geode* pyramidGeode;
    osg::Geometry* pyramidGeometry;
    //Associate the pyramid geometry with the pyramid geode
    //   Add the pyramid geode to the root node of the scene graph.

public:

	nave(int x,int y, int z, int tamaño)
		{
		pyramidGeode = new osg::Geode();
		pyramidGeometry = new osg::Geometry();
		pyramidGeode->addDrawable(pyramidGeometry);
		
		osg::Vec3Array* pyramidVertices = new osg::Vec3Array;
	
	//0-4
	pyramidVertices->push_back( osg::Vec3(       x,       y,       z) ); // front left
    //1-5
	pyramidVertices->push_back( osg::Vec3(tamaño+x,       y,       z) ); // front right
    //2-6
	pyramidVertices->push_back( osg::Vec3(tamaño+x,tamaño+y,       z) ); // back right
    //3-7
	pyramidVertices->push_back( osg::Vec3(       x,tamaño+y,       z) ); // back left
	//4-0
    pyramidVertices->push_back( osg::Vec3(	     x,		  y,tamaño+z) ); // peak
    //5-1
	pyramidVertices->push_back( osg::Vec3(tamaño+x,       y,tamaño+z) ); // front right
    //6-2
	pyramidVertices->push_back( osg::Vec3(tamaño+x,tamaño+y,tamaño+z) ); // back right
    //7-3
	pyramidVertices->push_back( osg::Vec3(       x,tamaño+y,tamaño+z) ); // back left	
		
	pyramidGeometry->setVertexArray( pyramidVertices );
		
		osg::DrawElementsUInt* pyramidBase =
        new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
    pyramidBase->push_back(3);
    pyramidBase->push_back(2);
    pyramidBase->push_back(1);
    pyramidBase->push_back(0);
    pyramidGeometry->addPrimitiveSet(pyramidBase);

	osg::DrawElementsUInt* pyramidTop =
        new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
    pyramidTop->push_back(4);
    pyramidTop->push_back(5);
    pyramidTop->push_back(6);
    pyramidTop->push_back(7);
    pyramidGeometry->addPrimitiveSet(pyramidTop);

    //Repeat the same for each of the four sides. Again, vertices are
    //specified in counter-clockwise order.

    osg::DrawElementsUInt* pyramidFaceOne =
        new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
    pyramidFaceOne->push_back(0);
    pyramidFaceOne->push_back(1);
	pyramidFaceOne->push_back(5);
    pyramidFaceOne->push_back(4);
	pyramidGeometry->addPrimitiveSet(pyramidFaceOne);

    osg::DrawElementsUInt* pyramidFaceTwo =
        new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
    pyramidFaceTwo->push_back(1);
    pyramidFaceTwo->push_back(2);
    pyramidFaceTwo->push_back(6);
	pyramidFaceTwo->push_back(5);
    pyramidGeometry->addPrimitiveSet(pyramidFaceTwo);

    osg::DrawElementsUInt* pyramidFaceThree =
        new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
    pyramidFaceThree->push_back(2);
    pyramidFaceThree->push_back(3);
    pyramidFaceThree->push_back(7);
	pyramidFaceThree->push_back(6);
    pyramidGeometry->addPrimitiveSet(pyramidFaceThree);

    osg::DrawElementsUInt* pyramidFaceFour =
        new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
    pyramidFaceFour->push_back(3);
    pyramidFaceFour->push_back(0);
    pyramidFaceThree->push_back(4);
	pyramidFaceFour->push_back(7);
    pyramidGeometry->addPrimitiveSet(pyramidFaceFour);

    //Declare and load an array of Vec4 elements to store colors.

    osg::Vec4Array* colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f) ); //index 0 red
    colors->push_back(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f) ); //index 1 green
    colors->push_back(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f) ); //index 2 blue
    colors->push_back(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f) ); //index 3 white
    colors->push_back(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f) ); //index 4 red
	 colors->push_back(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f) ); //index 4 red
	  colors->push_back(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f) ); //index 4 red
	   colors->push_back(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f) ); //index 4 red

    //The next step is to associate the array of colors with the geometry,
    //assign the color indices created above to the geometry and set the
    //binding mode to _PER_VERTEX.

    pyramidGeometry->setColorArray(colors);
    pyramidGeometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	
		};

	osg::Geode* getNave()
	{
	return pyramidGeode;
	};

};