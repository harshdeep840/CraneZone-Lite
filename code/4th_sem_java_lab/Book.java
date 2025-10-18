public class Book {
    private String title;
    private String author;
    private String isbn;
    private double price;
    public Book(String title, String author) {
        this.title = title;
        this.author = author;
    }

    public Book(String title, String author, String isbn, double price) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
        this.price = price;
    }
    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String getIsbn() {
        return isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }
    @Override
    public String toString() {
        return "Book{" +
                "title='" + title + '\'' +
                ", author='" + author + '\'' +
                ", isbn='" + isbn + '\'' +
                ", price=" + price +
                '}';
    }

    public static void main(String[] args) {

        Book book1 = new Book("Java Programming", "John Doe");
        System.out.println(book1);
        Book book2 = new Book("Clean Code", "Robert C. Martin", "978-0132350884", 29.99);
        System.out.println(book2);
    }
}
