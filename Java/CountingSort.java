class CountingSort {
    static void sort(int[] array, int radix){
        final int N = array.length;

        int[] aux = new int[N];
        int[] count = new int[radix + 1];

        for (int i = 0; i < N; i++)
            count[array[i] + 1]++;

        for (int i = 0; i < radix; i++)
            count[i + 1] += count[i];

        for (int i = 0; i < N; i++)
            aux[count[array[i]]++] = array[i];

        for (int i = 0; i < N; i++)
            array[i] = aux[i];
    }
}
