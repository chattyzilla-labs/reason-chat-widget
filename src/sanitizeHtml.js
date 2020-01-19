import markdownIt from 'markdown-it';
import markdownItSup from 'markdown-it-sup';
import markdownItSanitizer from 'markdown-it-sanitizer';
import markdownItLinkAttributes from 'markdown-it-link-attributes';

export const sanitizedHTML = (message) => {
        const sanitizedHTML = markdownIt()
        .use(markdownItSup)
        .use(markdownItSanitizer)
        .use(markdownItLinkAttributes, { attrs: { target: '_blank', rel: 'noopener' } })
        .render(this.props.message.get(message));
        return sanitizedHTML;
}

export default sanitizedHTML;