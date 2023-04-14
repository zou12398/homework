package dao;


import util.CRUDUtils;


public class RegisterDao {
    public static void regi(String username,String password) throws Exception {
        String sql="insert into user (username,password) values (?,?)";
        CRUDUtils.update(sql,username,password);
    }
}
