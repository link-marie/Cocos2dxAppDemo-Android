#include "AppMacros.h"
#include "AtlasLoader.h"

/**
 * Image loader manager from atlas.png
 */
AtlasLoader*AtlasLoader::sharedAtlasLoader = nullptr;

vector<string> split_naive( const string &s, char delim ) {
    vector<string> elems;
    string item;
    for( char ch: s ) {
        if( ch == delim ) {
            if( !item.empty())
                elems.push_back( item );
            item.clear();
        }
        else {
            item += ch;
        }
    }
    if( !item.empty())
        elems.push_back( item );
    return elems;
}

void parseLine( const string &s, char*name, int &x, int &y, int &width, int &height ) {

    vector<string> tmp = split_naive( s, ' ' );
    strcpy( name, tmp[0].c_str());
    x = atoi( tmp[1].c_str());
    y = atoi( tmp[2].c_str());
    width = atoi( tmp[3].c_str());
    height = atoi( tmp[4].c_str());
}

AtlasLoader*AtlasLoader::getInstance() {
    if( sharedAtlasLoader == NULL ) {
        sharedAtlasLoader = new AtlasLoader();
        if( !sharedAtlasLoader->init()) {
            delete sharedAtlasLoader;
            sharedAtlasLoader = NULL;
            CCL( "ERROR: Could not init sharedAtlasLoader" );
        }
    }
    return sharedAtlasLoader;
}

void AtlasLoader::destroyInstance() {
    CC_SAFE_DELETE( sharedAtlasLoader );
}

AtlasLoader::AtlasLoader() {
}

AtlasLoader::~AtlasLoader() {
}

bool AtlasLoader::init() {
    return true;
}

void AtlasLoader::loadAtlas( string filename ) {
    auto textureAtlas = Director::getInstance()->getTextureCache()->addImage( "atlas.png" );
    this->loadAtlas( filename, textureAtlas );
}

void AtlasLoader::loadAtlas( string filename, Texture2D*texture ) {

    /*
     int width = texture->getPixelsWide();
     int height = texture->getPixelsHigh();
     CCL( "loadAtlas w=%d h=%d" , width, height);
     */
    auto director = Director::getInstance();
    float scale = 1.0f/director->getContentScaleFactor();

    string data = FileUtils::getInstance()->getStringFromFile( filename );
    unsigned pos;
    Atlas atlas;
    pos = data.find_first_of( "\n" );
    string line = data.substr( 0, pos );
    data = data.substr( pos + 1 );
    while( line != "" ) {

        int x;
        int y;
        int width;
        int height;
        parseLine( line, atlas.name, x, y, width, height );

        atlas.start.x = x*scale;
        atlas.start.y = y*scale;

        atlas.width = width*scale;
        atlas.height = height*scale;

        pos = data.find_first_of( "\n" );
        line = data.substr( 0, pos );
        data = data.substr( pos + 1 );

        // use the data to create a sprite frame
        // fix 1px edge bug
        if( atlas.name == string( "land" )) {
            atlas.start.x += 1;
        }
        Rect rect = Rect( atlas.start.x, atlas.start.y, atlas.width, atlas.height );
        auto frame = SpriteFrame::createWithTexture( texture, rect );
        this->_spriteFrames.insert( string( atlas.name ), frame );
    }
}

SpriteFrame*AtlasLoader::getSpriteFrameByName( string name ) {
    return this->_spriteFrames.at( name );
}
