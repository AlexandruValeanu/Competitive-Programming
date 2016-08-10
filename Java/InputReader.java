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
