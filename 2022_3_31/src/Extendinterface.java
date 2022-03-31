import com.sun.jmx.snmp.SnmpUnknownAccContrModelException;

public class Extendinterface {
    public static void main(String[] args) {
        LittleMonkey wuKong = new LittleMonkey("悟空");
        wuKong.climbing();
        wuKong.swimming();
        wuKong.flying();
    }
}
//猴子
class Monkey{
    private String name;
    public Monkey() {
    }

    public Monkey(String name) {
        this.name = name;
    }
    public void climbing(){
         System.out.println("猴子会爬树");
     }
}
//接口
interface Fishable{
    void swimming();

}
interface Birdable
{
    void flying();
}
//继承
//子类继承父类，就自动拥有父类的功能
//如果子类需要扩展功能，可以通过实现接口的方式实现
//可以理解实现接口是对java单继承机制的一种补充
class LittleMonkey extends Monkey implements Fishable,Birdable{
    public LittleMonkey(String name) {
        super(name);
    }

    @Override
    public void swimming() {
        System.out.println("通过学习，可以像鱼儿一样游泳");
    }

    @Override
    public void flying() {
        System.out.println("通过学习，可以像鸟儿一样飞翔");
    }
}

