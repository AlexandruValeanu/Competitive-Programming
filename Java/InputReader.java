class InputReader{
    private BufferedReader reader;
    private StringTokenizer tokenizer;
    private InputStream inputStream;

    InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 1 << 20);
        tokenizer = null;
        inputStream = stream;
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

    void close() throws IOException {
        inputStream.close();
    }
}
