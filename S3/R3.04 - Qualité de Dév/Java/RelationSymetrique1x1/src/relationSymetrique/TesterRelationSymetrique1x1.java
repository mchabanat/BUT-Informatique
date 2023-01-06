package relationSymetrique;
import relationSymetrique.Client;
import relationSymetrique.Table;


public class TesterRelationSymetrique1x1 {

	public static void main(String[] args) {
		Client client1 = new Client("Martin","0101010101");
		Client client2 = new Client("Durand","0202020202");
		Table table1 = new Table("t01");
		Table table2 = new Table("t02");
		
		/*System.out.println (client1.toString());
		System.out.println (client2.toString());
		System.out.println (table1.toString());
		System.out.println (table2.toString());*/
		
		client1.lierMaTable(table1);
		table1.lierMonClient(client1);
		
		client2.lierMaTable(table2);
		table2.lierMonClient(client2);
		
		/*System.out.println (client1.toString());
		System.out.println (client2.toString());
		System.out.println (table1.toString());
		System.out.println (table2.toString());*/
		
		client1.lierMaTable(table2);
		table2.lierMonClient(client1);
		
		System.out.println (client1.toString());
		System.out.println (client2.toString());
		System.out.println (table1.toString());
		System.out.println (table2.toString());
	}

}
