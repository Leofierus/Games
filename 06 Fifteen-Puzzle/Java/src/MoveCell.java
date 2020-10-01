public class MoveCell {
    public MoveCell() {
    }

    static int up(int curPos, int level) {
        return curPos / level == level - 1 ? -1 : curPos + level;
    }

    static int down(int curPos, int level) {
        return curPos / level == 0 ? -1 : curPos - level;
    }

    static int left(int curPos, int level) {
        return (curPos + 1) % level == 0 ? -1 : curPos + 1;
    }

    static int right(int curPos, int level) {
        return curPos % level == 0 ? -1 : curPos - 1;
    }
}
