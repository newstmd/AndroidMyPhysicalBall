#include "AppDelegate.h"
#include "MainItem.h"
#include "AgentManager.h"
//#include "ResultScene.h"
#include "../../protocols/include/AgentManager.h"
USING_NS_CC;
using namespace anysdk::framework;
AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
	log("初始化ANYSDK代码");
	std::string appKey = "A2952517-9471-8C7E-9E6B-8776DEE841B2";
	std::string appSecret = "53f5a211696bc2f7b8bd1967137220c4";
	std::string privateKey = "598A8AB6287D7F8783CF160980D40251";
	std::string oauthLoginServer = "http://oauth.anysdk.com/api/OauthLoginDemo/Login.php";

	AgentManager::getInstance()->init(appKey,appSecret,privateKey,oauthLoginServer);
	log("初始化ANYSDK代码结束");
	AgentManager::getInstance()->loadALLPlugin();

    
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
                glview = GLViewImpl::createWithRect("MyPhysicalBall",cocos2d::Rect(0, 0, 640, 1136));
        director->setOpenGLView(glview);
    }

    director->getOpenGLView()->setDesignResolutionSize(640, 1136, ResolutionPolicy::FIXED_HEIGHT);

    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 120);

    FileUtils::getInstance()->addSearchPath("res");

    // create a scene. it's an autorelease object
    auto scene =MainItemScene::createScene();

    // run
    director->runWithScene(scene);
//    CGRect frameBanner = CGRectMake(0.0f, 0.0f, 320.0f, 50.0f);
//    CSBannerView *bannerView = [[CSBannerView alloc] initWithFrame:frameBanner];
//    [bannerView loadRequest:[CSADRequest request]];
//    scene->addChild(bannerView);
    //glview->get

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    //umeng::MobClickCpp::applicationDidEnterBackground();
    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
    //umeng::MobClickCpp::applicationWillEnterForeground();
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

