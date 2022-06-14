class Engine {
    public void start() {
    }

    public void rev() {
    }

    public void stop() {
    }
}

class Wheel {
    public void inflate(int psi) {
        System.out.println("汽车的轮胎转动了");
    }
}

class Window {
    public void rollup() {
    }

    public void rolldown() {
    }
}

class Door {
    public Window window = new Window();

    public void open() {
    }

    public void close() {
    }
}
public class Test1 {
    public Engine engine = new Engine();
    public Wheel[] wheel = new Wheel[4];
    public Door left = new Door();
    public Door right =new Door();
    public Test1()
    {
        for(int i=0;i<4;i++)
        {
            wheel[i] = new Wheel();
        }
    }
    public static void main(String[] args) {
        Test1 car = new Test1();
        car.left.window.rollup();
        car.wheel[0].inflate(72);
    }
}

