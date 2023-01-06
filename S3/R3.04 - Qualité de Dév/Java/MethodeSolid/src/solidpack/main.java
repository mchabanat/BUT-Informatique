package solidpack;
import solidpack.TraiterDate;
import solidpack.Date;

public class main {

	public static void main(String[] args) {
		Date maDate = new Date(2015,11,13);
		TraiterDate traiterUneDate = new TraiterDate(maDate);
		
		System.out.println(traiterUneDate.toInt());
	}

}
