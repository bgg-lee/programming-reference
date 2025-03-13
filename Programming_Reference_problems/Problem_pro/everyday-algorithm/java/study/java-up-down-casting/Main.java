public class Main 
{
    public static void main(String[] args)
    {
    	ParentFirst p1 = new ChildFirst();
    	ChildFirst c1 = (ChildFirst)p1;

		ParentSecond p2 = new ChildSecond();
		ChildSecond c2 = (ChildSecond)p2;

    	p1.print(0, "김진영"); 
    	System.out.println("나이 : "+ p1.age);
    	System.out.println("이름 : "+ p1.name);

        c1.print();	
        System.out.println("나이 : "+ c1.age);
    	System.out.println("이름 : "+ c1.name);

		p2.print(); 
    	System.out.println("나이 : "+ p2.age);	
    	System.out.println("이름 : "+ p2.name);

		c2.print();	
        System.out.println("나이 : "+ c2.age);
    	System.out.println("이름 : "+ c2.name);

		/*                                                                                   
			ParentFirst method :0
			ParentFirst method :김진영
			나이 : 0
			이름 : 김진영
			ChildFirst method :25
			ChildFirst method :이우원
			나이 : 25
			이름 : 이우원
			ChildSecond method :27
			ChildSecond method :이량화
			나이 : 55
			이름 : 두번째 부모
			ChildSecond method :27
			ChildSecond method :이량화
			나이 : 27
			이름 : 이량화
		*/
    }
}