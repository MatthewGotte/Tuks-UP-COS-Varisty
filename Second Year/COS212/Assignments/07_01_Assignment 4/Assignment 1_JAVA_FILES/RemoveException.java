@SuppressWarnings("serial")
public class RemoveException extends Exception {

    private String message;

    public RemoveException(String var1) {
        this.message = var1;
    }

    public String getMessage() {
        return this.message;
    }
}