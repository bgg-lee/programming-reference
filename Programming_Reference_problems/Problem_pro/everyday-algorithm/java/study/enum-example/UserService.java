public class UserService {
   public static final int MIN_LOGCOUNT_FOR_SILVER = 50;
   public static final int MIN_RECOMMEND_FOR_GOLD = 30;
   private UserDao userDao;

   public void setUserDao(UserDao userDao) {
      this.userDao = userDao;
   }

   public void upgradeLevels() {
      List<User> users = userDao.getAll();

      for (User user : users) {
         if (canUpgradeLevel(user)) {
            upgradeLevel(user);
         }
      }
   }

   public void add(User user) {
      if (user.getLevel() == null) {
         user.setLevel(Level.BASIC);
      }

      userDao.add(user);
   }

   //변경
   private boolean canUpgradeLevel(User user) {
      Level currentLevel = user.getLevel();
      return currentLevel.canUpgradeLevel(user);
   }

   protected void upgradeLevel(User user) {
      user.upgradeLevel();
      userDao.update(user);
   }

}