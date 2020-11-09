import java.text.DecimalFormat;
import java.util.Collection;
import java.util.Vector;

public class Main {

    private static <E> void startFinder(Collection<E> collection, IMatcher<E> matcher) {
        long start = System.nanoTime();
        E elem = Finder.findIf(collection.iterator(), matcher);
        long stop = System.nanoTime();

        double time = (stop -start)/1000000000.0;
        DecimalFormat f = new DecimalFormat("0.00");

        if (elem == null) {
            System.out.println("No match found in " + f.format(time) + " seconds.");
        }
        else {
            System.out.println("Found match in " + f.format(time) + " seconds.");
        }
    }

    public static void main(String[] args) {

        int size = 100000000;
        int target = 0;
        Collection<Integer> collection = new Vector<>(size);

        for (int i = 0; i < size-1; i++) {
            collection.add(1);
        }
        collection.add(target);

        IMatcher<Integer> matcher = (Integer toMatch) -> target == toMatch;
        startFinder(collection, matcher);
    }
}
