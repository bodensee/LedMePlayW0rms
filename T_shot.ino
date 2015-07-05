class Shot
{
    private:
        Point position;
        int   direction;
        
    public:
        Point getPosition();
        void goToNextPosition();
        void move();
        void remove();
        Shot();
        Shot(Point newPosition, int newDirection);
};

Point Shot::getPosition()
{
    return position;   
}

void Shot::goToNextPosition()
{
    if (direction == DIRECTION_UP)
    {
        --position.y;
    }
    else if (direction == DIRECTION_DOWN)
    {
         ++position.y;
    }
    else if (direction == DIRECTION_LEFT)
    {
        --position.x;
    }
    else if (direction == DIRECTION_RIGHT)
    {
        ++position.x;
    }
}

void Shot::move()
{
    remove();
    goToNextPosition();
    
    _P_YELLOW(position.x, position.y);
}

void Shot::remove()
{
    _OFF(position.x, position.y);
}

Shot::Shot()
{
    
}

Shot::Shot(Point newPosition, int newDirection)
{
    direction = newDirection;
    position  = newPosition;
    
    goToNextPosition();
}