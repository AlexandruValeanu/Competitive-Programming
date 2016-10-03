class InputReader implements AutoCloseable{
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

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

    public String nextString(){
        return nextToken();
    }

    public void close() {
        try {
            inputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
