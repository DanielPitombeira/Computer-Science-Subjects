#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace std;
sf::Font font;

typedef long long ll;

const int N = int(1e5+10);
const int radius = 30; //30
const int horizontalSpacing = 80; //60
const int verticalSpacing = 160; //80

vector<int>ad[N];

struct TreeNode {
    int x, y, value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int getTreeHeight(TreeNode* root){
    if(root == nullptr) return 0;

    return max(getTreeHeight(root->left) + 1, getTreeHeight(root->right) + 1);
}

void setCoordinates(TreeNode* root, int x, int y, int horizontalSpacing) {
    if(root == nullptr){
        return;
    }

    root->x = x;
    root->y = y;

    setCoordinates(root->left, x - horizontalSpacing, y + verticalSpacing, horizontalSpacing / 2);
    setCoordinates(root->right, x + horizontalSpacing, y + verticalSpacing, horizontalSpacing / 2);
}

void drawCircleWithText(sf::RenderWindow& window, int x, int y, int value){
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

void drawTree(sf::RenderWindow& window, TreeNode* root, sf::View& view) {
    if(root == nullptr){
        return;
    }

    sf::Vector2f center = view.getCenter();
    sf::Vector2f size = view.getSize();

    // Verifica se o vértice está dentro da janela visível
    if(root->x >= center.x - size.x / 2 && root->x <= center.x + size.x / 2 && root->y >= center.y - size.y / 2 && root->y <= center.y + size.y / 2){
        drawCircleWithText(window, root->x, root->y, root->value);
    }

    if(root->left){
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(root->x, root->y + radius)),
            sf::Vertex(sf::Vector2f(root->left->x, root->left->y - radius))
        };
        window.draw(line, 2, sf::Lines);
    }

    if(root->right){
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(root->x, root->y + radius)),
            sf::Vertex(sf::Vector2f(root->right->x, root->right->y - radius))
        };
        window.draw(line, 2, sf::Lines);
    }

    drawTree(window, root->left, view);
    drawTree(window, root->right, view);
}

int main() {
    font.loadFromFile("arial.ttf");

    int n = 63;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        values[i] = i + 1;
    }

    // Build the binary tree
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(values[0]);
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n) {
        TreeNode* current = q.front();
        q.pop();

        if(i < n){
            current->left = new TreeNode(values[i]);
            q.push(current->left);
            i++;
        }

        if(i < n){
            current->right = new TreeNode(values[i]);
            q.push(current->right);
            i++;
        }
    }

    int treeHeight = getTreeHeight(root);

    int windowHeight = treeHeight * verticalSpacing + 100;
    int windowWidth = pow(2, treeHeight) * horizontalSpacing + 100;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Binary Tree Visualization");

    setCoordinates(root, windowWidth / 2, 50, windowWidth / 4);

    // Configura uma visualização inicial
    sf::View view(sf::FloatRect(0, 0, windowWidth, windowHeight));
    window.setView(view);

    float zoomFactor = 1.0f; // Fator de zoom inicial

    sf::Vector2f lastMousePosition;
    bool isDragging = false;

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }

            if(event.type == sf::Event::MouseWheelScrolled){
                // Evento de rolagem do mouse para zoom
                if (event.mouseWheelScroll.delta > 0) {
                    // Aumenta o zoom
                    zoomFactor *= 1.1f;
                } else if (event.mouseWheelScroll.delta < 0) {
                    // Diminui o zoom
                    zoomFactor *= 0.9f;
                }

                // Atualiza a visualização com o novo zoom
                view.setSize(window.getSize().x / zoomFactor, window.getSize().y / zoomFactor);
                window.setView(view);
            }

            if(event.type == sf::Event::KeyPressed){
                // Lógica para rolagem usando as teclas de seta (exemplo)
                if (event.key.code == sf::Keyboard::Left) {
                    view.move(-40, 0);
                } else if (event.key.code == sf::Keyboard::Right) {
                    view.move(40, 0);
                } else if (event.key.code == sf::Keyboard::Up) {
                    view.move(0, -40);
                } else if (event.key.code == sf::Keyboard::Down) {
                    view.move(0, 40);
                }

                window.setView(view);
            }

            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
                // Inicia o arraste ao clicar com o botão esquerdo
                isDragging = true;
                lastMousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
            }

            if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
                // Finaliza o arraste ao soltar o botão esquerdo
                isDragging = false;
            }

            if(event.type == sf::Event::MouseMoved && isDragging){
                // Move a visualização com base no movimento do mouse durante o arraste
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