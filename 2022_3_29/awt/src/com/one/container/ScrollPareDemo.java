package com.one.container;

import java.awt.*;

public class ScrollPareDemo {
    public static void main(String[] args) {
        Frame frame=new Frame("������ʾScrollPane");
        //1������һ��ScroallPane����
        ScrollPane sp=new ScrollPane(ScrollPane.SCROLLBARS_ALWAYS);
        //2����ScroallPane���������
        sp.add(new TextField("���ǲ����ı�"));
        sp.add(new Button("���ǲ��԰�ť"));
        //3����ScroallPane��ӵ�Frame��
        frame.add(sp);
        frame.setBounds(100,100,500,300);
        frame.setVisible(true);

    }
}
