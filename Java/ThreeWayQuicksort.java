import java.util.Random;

class ThreeWayQuicksort {
    private static final int RADIX = 128;
    private static final int CUT_OFF = 10;

    public static void sort(String[] array){
        shuffle(array);
        sort(array, 0, array.length - 1, 0);
    }

    private static int charAt(String s, int d){
        if (d < s.length())
            return s.charAt(d);
        else
            return -1;
    }

    private static void swap(String[] array, int x, int y){
        String s = array[x];
        array[x] = array[y];
        array[y] = s;
    }

    private static boolean less(String u, String v, int d){
        return u.substring(d).compareTo(v.substring(d)) < 0;
    }

    private static void insertionSort(String[] array, int lo, int hi, int d){
        for (int i = lo; i <= hi; i++)
            for (int j = i; j > lo && less(array[j], array[j - 1], d); j--)
                swap(array, j, j - 1);
    }

    private static void shuffle(String[] array){
        Random random = new Random();

        for (int i = 1; i < array.length; i++){
            int j = random.nextInt(i + 1);

            if (i != j)
                swap(array, i, j);
        }
    }

    private static void sort(String[] array, int lo, int hi, int d){
        if (lo + CUT_OFF >= hi)
            insertionSort(array, lo, hi, d);
        else{
            int lt = lo, gt = hi;
            int pivot = charAt(array[lo], d);
            int i = lo + 1;

            while (i <= gt){
                int c = charAt(array[i], d);

                if (c < pivot)
                    swap(array, lt++, i++);
                else if (c > pivot)
                    swap(array, i, gt--);
                else
                    i++;
            }

            sort(array, lo, lt - 1, d);
            sort(array, gt + 1, hi, d);

            if (pivot >= 0)
                sort(array, lt, gt, d + 1);
        }
    }
}
