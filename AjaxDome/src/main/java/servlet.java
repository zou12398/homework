import com.alibaba.fastjson.JSON;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

@WebServlet("/servlet")
public class servlet extends HttpServlet {
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
        List<user> users=new ArrayList<>();
        try {
            rs=state.executeQuery(sql);
            while(rs.next()){
                user a=new user();
                a.setUsername(rs.getString("username"));
                a.setPassword(rs.getString("password"));
                users.add(a);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        String jsonString= JSON.toJSONString(users);
        resp.setContentType("text/html;charset=utf-8");
        resp.getWriter().write(jsonString);
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        this.doGet(req, resp);
    }
}
