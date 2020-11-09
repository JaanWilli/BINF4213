import java.util.Iterator;

public class Finder {

    public static <E> E findIf(Iterator<E> iter, IMatcher<E> matcher) {
        E elem;

        while(iter.hasNext()) {
            elem = iter.next();
            if (matcher.match(elem)) {
                return elem;
            }
        }
        return null;
    }
}
