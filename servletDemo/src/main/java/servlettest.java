import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;
import java.util.Map;
import java.util.Objects;

@WebServlet("/demo1")
public class servlettest extends HttpServlet {

    static ResultSet rs;
    static Connection conn;
    static String sql="select* from user";
    static Statement state;


    static {
        {
            try {
                Class.forName("com.mysql.cj.jdbc.Driver");
                conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/test", "root", "Zou1166881979");
                state = conn.createStatement();

            } catch (SQLException | ClassNotFoundException e) {
                throw new RuntimeException(e);
            }
        }
    }


    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        resp.setContentType("text/html;charset=utf-8");
        Map<String,String[]> map=req.getParameterMap();
        String username=req.getParameter("username");
        String password=req.getParameter("password");
        PrintWriter writer=resp.getWriter();
        if(username == null | password == null|Objects.equals(username, "") | Objects.equals(password, "")){
            writer.write("<h1>未输入信息</h1>");
            return;
        }
        String pass=null;
        String name=null;
        try {
            rs=state.executeQuery(sql);
            while (rs.next()){
                name= rs.getString("username");
                pass= rs.getString("password");
                if(pass.equals(password)&&name.equals(username)){
                    break;
                }else {
                    name=null;
                    pass=null;
                }
            }
            //resp.sendRedirect("/servletDemo/demo2");
            if(name!=null&pass!=null) {
                writer.write("<h1>登陆成功</h1>");
            }else{
                writer.write("<h1>登陆失败</h1>");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        this.doGet(req, resp);
    }
}
