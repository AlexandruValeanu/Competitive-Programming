import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);

        int T = in.nextInt();

        while (T-- > 0){
            int N = in.nextInt();
            int[][] menPreffs = new int[N][N];
            int[][] womenPreffs = new int[N][N];

            for (int i = 0; i < N; i++) {
                int x = in.nextInt();
                for (int j = 0; j < N; j++) {
                    womenPreffs[i][j] = in.nextInt() - 1;
                }
            }

            for (int i = 0; i < N; i++) {
                int x = in.nextInt();
                for (int j = 0; j < N; j++) {
                    menPreffs[i][j] = in.nextInt() - 1;
                }
            }

            int[] marriages = stableMarriage(menPreffs, womenPreffs);

            for (int i = 0; i < N; i++) {
                System.out.printf("%d %d\n", i + 1, marriages[i] + 1);
            }
        }
    }

    static int[] stableMarriage(int[][] menPreffs, int[][] womenPreffs){
        final int N = menPreffs.length;

        int[][] mapWomanToMan = new int[N][N];
        int[] womanMatch = new int[N];
        int[] manMatch = new int[N];

        for (int i = 0; i < N; ++i){
            womanMatch[i] = -1;
            manMatch[i] = -1;
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                mapWomanToMan[i][ womenPreffs[i][j] ] = j;

        Queue<Integer> bachelors = new LinkedList<>();

        for (int i = 0; i < N; i++) {
            bachelors.add(i);
        }

        while (!bachelors.isEmpty()){
            int man = bachelors.remove();

            for (int woman : menPreffs[man]){
                if (womanMatch[woman] == -1){
                    womanMatch[woman] = man;
                    manMatch[man] = woman;
                    break;
                }
                else{
                    int otherMan = womanMatch[woman];

                    if (mapWomanToMan[woman][man] < mapWomanToMan[woman][otherMan]){
                        bachelors.add(otherMan);
                        manMatch[otherMan] = -1;

                        womanMatch[woman] = man;
                        manMatch[man] = woman;
                        break;
                    }
                }
            }
        }

        return manMatch;
    }

    static class InputReader{
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 65536);
            tokenizer = null;
        }

        private String nextToken() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()){
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                }
                catch (IOException e){
                    throw new RuntimeException(e);
                }
            }

            return  tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        String nextString(){
            return nextToken();
        }
    }
}
