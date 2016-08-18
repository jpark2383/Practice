/* Java Version 1.8.0_101 */

public class ContactSearch
{
    public static void main(String []args) throws IOException {
    	Scanner scanner = new Scanner(System.in);
    	System.out.println("Please enter the filepath: ");
        String path = scanner.next();
        try {
        	Reader(path);
        }
        catch (FileNotFoundException e) {
        	System.out.println("File not found, please check to make sure file exists");
        }
    }

    public static void Reader(String filepath) throws FileNotFoundException, IOException {
    	Scanner choiceScan = new Scanner(System.in);
    	System.out.println("Please enter 1 to search a contact and 2 to find all contacts starting with a letter");
        int choice = choiceScan.nextInt();
        choiceScan.nextLine();
        String findEmail = "";
        String firstLetter = "";
        if (choice == 1) {
        	choiceScan = new Scanner(System.in);
        	System.out.println("Please enter the email to search");
        	findEmail = choiceScan.next();
        	choiceScan.nextLine();
        }
        else if (choice == 2) {
        	choiceScan = new Scanner(System.in);
    		System.out.println("Please enter the first letter of the last name");
    		firstLetter = choiceScan.next().toUpperCase();
    		choiceScan.nextLine();
        }
    	Map<String, Person> infoMap = new HashMap<String, Person>();
    	infoMap.clear();
    	try {
	    	Scanner scanner = new Scanner(new File(filepath));
	    	String line;
	    	String[] lineVector = new String[4];
	    	List<Pair> lastnames = new ArrayList<Pair>();
	    	while (scanner.hasNext()) {
	    		line = scanner.nextLine();
	    		lineVector = line.split(",");
	    		Person person = new Person();
	    		person.first = lineVector[0];
	    		person.last = lineVector[1];
	    		person.email = lineVector[2];
	    		person.phone = lineVector[3];
	    		if (!infoMap.containsKey(person.email)) {
	    			if (person.last.startsWith(firstLetter)) {
	    				Pair p = new Pair();
	    				p.l = person.last;
	    				p.e = person.email;
	    				lastnames.add(p);
	    			}
	    			infoMap.put(person.email,person);
	    		}
	    	}
	    	scanner.close();
	    	if (choice == 1) {
	    		Search(infoMap, findEmail);
	    	}
	    	else if (choice == 2) {
	    		printName(infoMap, lastnames, firstLetter);
	    	}
	    	else {
	    		System.out.println("Choice was not valid");
	    	}
	    		    	
	    }
	    catch (FileNotFoundException ex) {
	    	System.out.println("File not found, please check to make sure file exists");
	    }
    }

    public static void Search(Map<String, Person> info, String emailToSearch) {
    	if(info.get(emailToSearch) != null) {
    			StringBuffer output = new StringBuffer();
	    		output.append("Last: ");
	    		output.append(info.get(emailToSearch).last);
				output.append(", First: ");
				output.append(info.get(emailToSearch).first);
				output.append(", Phone: ");
				output.append(info.get(emailToSearch).phone);
				output.append(", E-Mail: ");
				output.append(emailToSearch);
				System.out.println(output);
    	}	
    }

    public static void printName(Map<String, Person> info, List<Pair> lnames, String starting) {
    	Pair [] lnameArray = new Pair[lnames.size()];
    	lnames.toArray(lnameArray);
    	Arrays.sort(lnameArray, new Comparator<Pair>() {
    		@Override
    		public int compare(Pair a1, Pair a2)
    		{
    			return a1.getL().compareTo(a2.getL());
    		}
    	});
    	int size = lnames.size();
    	for(int i = 0; i < size; i++) {
			StringBuffer output = new StringBuffer();
    		output.append("Last: ");
    		output.append(info.get(lnameArray[i].e).last);
			output.append(", First: ");
			output.append(info.get(lnameArray[i].e).first);
			output.append(", Phone: ");
			output.append(info.get(lnameArray[i].e).phone);
			output.append(", E-Mail: ");
			output.append(lnameArray[i].l);
    		System.out.println(output);
    	}
    }

    private static class Person {
    	private String last;
    	private String first;
    	private String email;
    	private String phone;
    }

    private static class Pair {
    	private String l;
    	private String e;

    	public String getL() {
    		return l;
    	}

    	public String getE() {
    		return e;
    	}
    }
}
