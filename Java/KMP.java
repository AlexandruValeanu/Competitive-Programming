import java.util.Arrays;

class KMP {
    private static int[] buildPrefix(char[] pattern, int N){
        int lgPrefix = 0;

        int[] pi = new int[N + 1];
        Arrays.fill(pi, 0);

        for (int i = 2; i <= N; i++) {
            while (lgPrefix > 0 && pattern[i] != pattern[lgPrefix + 1])
                lgPrefix = pi[lgPrefix];

            if (pattern[i] == pattern[lgPrefix + 1])
                lgPrefix++;

            pi[i] = lgPrefix;
        }

        return pi;
    }

    private static int[] kmp(char[] pattern, int N, char[] text, int M, int[] pi){
        int lgPrefix = 0;

        int[] d = new int[M + 1];
        Arrays.fill(d, 0);

        for (int i = 1; i <= M; i++){
            while (lgPrefix > 0 && text[i] !=
                    pattern[lgPrefix + 1])
                lgPrefix = pi[lgPrefix];

            if (text[i] == pattern[lgPrefix + 1])
                lgPrefix++;

            d[i] = lgPrefix;

            if (lgPrefix == N){
                lgPrefix = pi[lgPrefix];
            }
        }

        return d;
    }

    public static int[] computePi(String string){
        final int N = string.length();

        char[] pattern = new char[N + 1];

        for (int i = 1; i <= N; i++) {
            pattern[i] = string.charAt(i - 1);
        }

        return buildPrefix(pattern, N);
    }

    public static int[] computeKMP(String _pattern, String _text){
        final int N = _pattern.length();
        final int M = _text.length();

        char[] pattern = new char[N + 1];
        char[] text = new char[M + 1];

        for (int i = 1; i <= N; i++)
            pattern[i] = _pattern.charAt(i - 1);

        for (int i = 1; i <= M; i++)
            text[i] = _text.charAt(i - 1);

        int[] pi = buildPrefix(pattern, N);
        return kmp(pattern, N, text, M, pi);
    }

    public static int findPeriod(String s){
        int[] d = computeKMP(s, s + s);
        final int N = s.length();
        int c = 0;

        for (int i = 1; i <= 2 * N; ++i){
            if (d[i] == N)
                c++;

            if (c == 2)
                return i - N;
        }

        return -1;
    }
}
