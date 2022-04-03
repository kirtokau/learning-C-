public class Student extends Person{
    public Student(String name, int age, double score) {
        super(name, age);
        this.score = score;
    }

    public double getScore() {
        return score;
    }

    public void setScore(double score) {
        this.score = score;
    }

    private double score;
    //重写父类say


    @Override
    public String say() {
        return "学生 "+super.say()+" score="+score;
    }
    //特有方法
    public void study(){
        System.out.println("学生"+getName()+"正在学java...");
    }
}
