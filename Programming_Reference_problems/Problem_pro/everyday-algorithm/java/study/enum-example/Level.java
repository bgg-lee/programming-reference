public enum Level {

    GOLD(3, null, (User user) -> false),
    SILVER(2, GOLD, (User user) -> user.getRecommend() > UserService.MIN_RECOMMEND_FOR_GOLD),
    BASIC(1, SILVER, (User user) -> user.getLogin() > UserService.MIN_LOGCOUNT_FOR_SILVER);

    private final int value;
    private final Level next;
    private Predicate<User> predicate;

    Level(int value, Level next, Predicate<User> predicate) {
        this.value = value;
        this.next = next;
        this.predicate = predicate;
    }

    public int intValue() {
        return value;
    }

    public Level nextLevel() {
        return this.next;
    }

    public static Level valueOf(int value) {
        switch (value) {
            case 1:
                return BASIC;
            case 2:
                return SILVER;
            case 3:
                return GOLD;
            default:
                throw new AssertionError("Unknown value: " + value);
        }
    }

    public boolean canUpgradeLevel(User user) {
        return predicate.test(user);
    }

}