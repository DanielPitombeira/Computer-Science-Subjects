#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = int(1e5 + 10);
const int radius = 30;
const int verticalSpacing = 160;
const int minimumHorizontalSpacing = 20;

vector<int> adj[N];
bool mark[N];
int altura[N];
int father[N];

int alt;

sf::Font font;

struct TreeNode
{
    int x, y, value, level;
    TreeNode *left;
    TreeNode *right;
    int height; 

    TreeNode(int val, int lvl) : value(val), level(lvl), left(nullptr), right(nullptr), height(1) {}
};

int getTreeHeight(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return max(getTreeHeight(root->left) + 1, getTreeHeight(root->right) + 1);
}

int getHeight(TreeNode *node)
{
    return (node == nullptr) ? 0 : node->height;
}

int getBalanceFactor(TreeNode *node)
{
    return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
}

void updateHeight(TreeNode *node)
{
    if (node != nullptr)
    {
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    }
}

TreeNode *leftRotate(TreeNode *x)
{
    TreeNode *y = x->right;
    x->right = y->left;
    y->left = x;

    updateHeight(x);
    updateHeight(y);

    return y;
}

TreeNode *rightRotate(TreeNode *y)
{
    TreeNode *x = y->left;
    y->left = x->right;
    x->right = y;

    updateHeight(y);
    updateHeight(x);

    return x;
}

TreeNode *insert(TreeNode *root, int value, int level)
{
    if (root == nullptr)
    {
        return new TreeNode(value, level);
    }

    if (value < root->value)
    {
        root->left = insert(root->left, value, level + 1);
    }
    else if (value > root->value)
    {
        root->right = insert(root->right, value, level + 1);
    }
    else
    {
        return root;
    }

    updateHeight(root);

    int balance = getBalanceFactor(root);

    if (balance > 1 && value < root->left->value)
    {
        return rightRotate(root);
    }
    if (balance < -1 && value > root->right->value)
    {
        return leftRotate(root);
    }
    if (balance > 1 && value > root->left->value)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && value < root->right->value)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

TreeNode *balanceTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return root;
    }

    updateHeight(root);

    int balance = getBalanceFactor(root);

    if (balance > 1 && getBalanceFactor(root->left) >= 0)
    {
        return rightRotate(root);
    }
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
    {
        return leftRotate(root);
    }
    if (balance > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void dfs(int v)
{
    if (v == 1)
        altura[v] = 1;

    mark[v] = true;

    for (int u : adj[v])
    {
        if (mark[u] == false)
        {
            father[u] = v;
            altura[u] = altura[v] + 1;
            dfs(u);
        }
    }
}

int height()
{
    dfs(1);

    sort(altura, altura + N);
    reverse(altura, altura + N);

    return altura[0];
}

int calculateHorizontalSpacing(int level)
{
    return minimumHorizontalSpacing * (1 << (altura[0] - level - 1));
}

void setCoordinates(TreeNode *root, int x, int y, int hSpacing)
{
    if (root == nullptr)
    {
        return;
    }

    root->x = x;
    root->y = y;

    if (root->left)
    {
        setCoordinates(root->left, x - hSpacing, y + verticalSpacing, hSpacing / 2);
    }

    if (root->right)
    {
        setCoordinates(root->right, x + hSpacing, y + verticalSpacing, hSpacing / 2);
    }
}

void drawCircleWithText(sf::RenderWindow &window, int x, int y, int value)
{
    sf::CircleShape circle(radius);
    circle.setPosition(x - radius, y - radius);
    circle.setFillColor(sf::Color::Magenta);
    window.draw(circle);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setString(to_string(value));
    text.setPosition(x - 10, y - 20);
    window.draw(text);
}

void drawTree(sf::RenderWindow &window, TreeNode *root, sf::View &view)
{
    if (root == nullptr)
    {
        return;
    }

    sf::Vector2f center = view.getCenter();
    sf::Vector2f size = view.getSize();

    if (root->x >= center.x - size.x / 2 && root->x <= center.x + size.x / 2 &&
        root->y >= center.y - size.y / 2 && root->y <= center.y + size.y / 2)
    {
        drawCircleWithText(window, root->x, root->y, root->value);
    }

    if (root->left)
    {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(root->x, root->y + radius)),
            sf::Vertex(sf::Vector2f(root->left->x, root->left->y - radius))};
        window.draw(line, 2, sf::Lines);
    }

    if (root->right)
    {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(root->x, root->y + radius)),
            sf::Vertex(sf::Vector2f(root->right->x, root->right->y - radius))};
        window.draw(line, 2, sf::Lines);
    }

    drawTree(window, root->left, view);
    drawTree(window, root->right, view);
}

int main()
{
    font.loadFromFile("arial.ttf");

    int n;
    cin >> n;

    TreeNode *root = nullptr;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        root = insert(root, a, 0);
        root = balanceTree(root);
        root = insert(root, b, 0);
        root = balanceTree(root);
    }

    alt = height();

    int treeHeight = getTreeHeight(root);
    int windowWidth = n * minimumHorizontalSpacing + 100; 
    int windowHeight = treeHeight * verticalSpacing + 100;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "AVL Tree Visualization");

    setCoordinates(root, windowWidth / 2, 50, calculateHorizontalSpacing(root->level));

    sf::View view(sf::FloatRect(0, 0, windowWidth, windowHeight));
    window.setView(view);

    float zoomFactor = 1.0f;
    sf::Vector2f lastMousePosition;
    bool isDragging = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseWheelScrolled)
            {
                if (event.mouseWheelScroll.delta > 0)
                {
                    zoomFactor *= 1.1f;
                }
                else if (event.mouseWheelScroll.delta < 0)
                {
                    zoomFactor *= 0.9f;
                }

                view.setSize(window.getSize().x / zoomFactor, window.getSize().y / zoomFactor);
                window.setView(view);
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left)
                {
                    view.move(-40, 0);
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    view.move(40, 0);
                }
                else if (event.key.code == sf::Keyboard::Up)
                {
                    view.move(0, -40);
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    view.move(0, 40);
                }

                window.setView(view);
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                isDragging = true;
                lastMousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
            }

            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                isDragging = false;
            }

            if (event.type == sf::Event::MouseMoved && isDragging)
            {
                sf::Vector2f newMousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
                sf::Vector2f delta = lastMousePosition - newMousePosition;
                view.move(delta);
                window.setView(view);
                lastMousePosition = newMousePosition;
            }
        }

        window.clear(sf::Color::Black);
        drawTree(window, root, view);
        window.display();
    }

    return 0;
}