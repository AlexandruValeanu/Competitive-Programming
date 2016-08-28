import java.util.Arrays;

class LSD_RadixSort {
    static void sort(String[] array, int W){
        final int N = array.length;
        final int RADIX = 128;

        String[] aux = new String[N];
        int[] count = new int[RADIX + 1];

        for (int d = W - 1; d >= 0; d--) {

            for (int i = 0; i < N; i++)
                count[array[i].charAt(d) + 1]++;

            for (int i = 0; i < RADIX; ++i)
                count[i + 1] += count[i];

            for (int i = 0; i < N; ++i)
                aux[count[array[i].charAt(d)]++] = array[i];

            for (int i = 0; i < N; ++i)
                array[i] = aux[i];

            Arrays.fill(count, 0);
        }
    }
}
