#include <criterion/criterion.h>
#include "./TestRenderable.hpp"

// Test de création d'une instance Renderable avec sf::Texture
Test(Renderable, CreateWithSfTexture) {
    sf::Texture texture;
    texture.loadFromFile(PATH_TO_TEXTURE);

    Renderable renderable(texture);

    cr_assert(renderable._texture.getSize().x > 0);
    cr_assert(renderable._texture.getSize().y > 0);
}

// Test de création d'une instance Renderable avec le chemin du fichier de texture
Test(Renderable, CreateWithTextureFilePath) {
    Renderable renderable(PATH_TO_TEXTURE);

    cr_assert(renderable._texture.getSize().x > 0);
    cr_assert(renderable._texture.getSize().y > 0);
}
