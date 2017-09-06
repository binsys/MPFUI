// 华勤科技版权所有 2010-2011
// 
// 文件名：MainWindow.h
// 功  能：主界面窗口。
// 
// 作  者：MPF开发组
// 时  间：2013-01-02
// 
// ============================================================================

#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include "PlayManager.h"

class MainWindow : public suic::Window
{
public:

    // 事件映射
    BeginRoutedEvent(MainWindow, suic::Window)
        MemberRouted(OnClickButton)
        MemberRouted(OnClickOpenButton)
        MemberRouted(OnClickStopButton)
        MemberRouted(OnClickFullButton)
        MemberRouted(OnClickBrowserButton)
        MemberRouted(OnClickPrevButton)
        MemberRouted(OnClickNextButton)
    EndRoutedEvent()

    MainWindow();
    ~MainWindow();

    void SetFullScreenMode(bool bFull);

    void OnLoaded(suic::LoadedEventArg* e);

    void OnClickButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickOpenButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickStopButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickFullButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickBrowserButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickPrevButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickNextButton(suic::DpObject* sender, suic::RoutedEventArg* e);

    void OnVolumeChanged(suic::Element*, suic::FloatPropChangedEventArg* e);
    void OnPlayProgressChanged(suic::Element*, suic::FloatPropChangedEventArg* e);
    void OnDblPlayListClick(suic::Element* sender, suic::MouseButtonEventArg* e);
    void OnPlayListSelectionChanged(suic::Element* sender, suic::SelectionChangedEventArg* e);

protected:

    void OnRenderSizeChanged(suic::SizeChangedInfo& sizeInfo);
    void OnPreviewMouseMove(suic::MouseButtonEventArg* e);
    void OnKeyDown(suic::KeyboardEventArg* e);
    void OnPreviewMouseLeftButtonDown(suic::MouseButtonEventArg* e);

    void OnCheckMouseMove(suic::Object* sender, suic::EventArg* e);

    void Dispose();
    
    void PlayCallback(bool start, int index);

    void ShowBottomStatus(bool bShow);
    void ShowRightPlayPanel(bool bShow);

protected:

    // 创建自己的控件对象
    bool OnBuild(suic::IXamlNode* pNode, suic::ObjectPtr& obj);
    void OnConnect(suic::IXamlNode* pNode, suic::Object* target);

private:

    PlayManager* _playManager;

    suic::ListBox* _playListBox;
    suic::FrameworkElement* _playArea;
    suic::FrameworkElement* _layBottom;
    suic::FrameworkElement* _layRight;

    suic::Point _lastMousePt;
    // 定时器，用来检测在全屏状态时鼠标停留时间
    // 根据停留时间长短显示状态栏
    suic::AssignerTimer* _timer;
};

#endif
