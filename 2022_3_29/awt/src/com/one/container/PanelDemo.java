package com.one.container;

import java.awt.*;

public class PanelDemo {
    public static void main(String[] args) {
        //1、创建一个window对象，Panel及其它容器必须依赖window存在
        Frame frame=new Frame("这里演示Pannel");
        //2、创建一个Demo对象
        Panel p=new Panel();
        //3、创建一个文本框和按钮，把他们放入Panel容器中
        p.add(new TextField("这里是一个测试文本"));
        p.add(new Button("这里是一个测试按钮"));
        //4、把Panel放入到Window中
        frame.add(p);
        //5、设置window的位置及大小
        frame.setBounds(100,100,500,300);
        //6、设置window可见
        frame.setVisible(true);

    }
}
